#include "GameApp.h"

GameApp::GameApp(): mSpaceship("assets/unknown.png", 5), 
					mBackground("assets/oceanBackground.png"),
					mGameOverMessage("assets/GameOver.png"),
					mSpaceshipAction(Action::Forward), 
					mFrameNumber(0), mGameEnd(false)
{ }

void GameApp::OnUpdate()
{
	Hunter::Renderer::Draw(mBackground, 0, 0, GameApp::GetWindowWidth(), GameApp::GetWindowHeight());
	if (mGameEnd)
	{
		Hunter::Renderer::Draw(mGameOverMessage, 250, 150, mGameOverMessage.GetWidth(), mGameOverMessage.GetHeight());
		return;
	}

	if (mFrameNumber % 30 == 0) //four times per second, gen a new planet
	{
		std::string planetType{ "assets/fish.png" }; // with random planets/assets use std::string planetType{"assets/fish" + std::to_string(rand()%5+1) + ".png"};
		mPlanets.emplace_back(planetType, 10); //emplace_back - (check cplusplus for more) takes arguments for Unit constructor and constructs it in-q
		mPlanets.back().SetYCoord(GameApp::GetWindowHeight());
		mPlanets.back().SetXCoord(rand() % (GameApp::GetWindowWidth() - mPlanets.back().GetWidth()));
	}

	//Spaceship movement
	if (mSpaceshipAction == Action::LeftMove)
	{
		if (mSpaceship.GetXCoord() >= mSpaceship.GetSpeed())
			mSpaceship.UpdateXCoord(-mSpaceship.GetSpeed());

		else
			mSpaceship.SetXCoord(0);
	}

	else if (mSpaceshipAction == Action::RightMove)
	{
		if (mSpaceship.GetXCoord() + mSpaceship.GetWidth() + mSpaceship.GetSpeed() <= GameApp::GetWindowWidth()) //if we want to go right, lets check if its valid move
			mSpaceship.UpdateXCoord(mSpaceship.GetSpeed());

		else
			mSpaceship.SetXCoord(GameApp::GetWindowWidth() - mSpaceship.GetWidth());
	}

	while (!mPlanets.empty() && mPlanets.front().GetYCoord() <= -mPlanets.front().GetHeight())
		mPlanets.pop_front();

	// Move planet down
	for (auto& planet : mPlanets)
	{
		planet.UpdateYCoord(-planet.GetSpeed());

		if (planet.OverlapsWith(mSpaceship))
			mGameEnd = true;
	}

	for (const auto& planet : mPlanets)
		planet.Draw();

	mSpaceship.Draw();

	mFrameNumber++;
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent & event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
	{
		mSpaceshipAction = Action::LeftMove;
	}

	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
	{
		mSpaceshipAction = Action::RightMove;
	}
}

void GameApp::OnKeyReleased(Hunter::KeyReleasedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT || event.GetKeyCode() == HUNTER_KEY_RIGHT)
		mSpaceshipAction = Action::Forward;
}