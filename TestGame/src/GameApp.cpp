#include "GameApp.h"

GameApp::GameApp(): mFlySwatter("assets/unknown.png", 6), 
					mTitle("assets/title.png"),
					mInstructions("assets/howToPlay.png"),
					mBackground("assets/woodenWall.png"),
					mScore(0),
					mGameOverMessage("assets/GameOver.png"),
					mFlySwatterAction(Action::Forward), 
					mFrameNumber(0), mGameEnd(false)
{ }

void GameApp::OnUpdate()
{
	Hunter::Renderer::Draw(mBackground, 0, 0, mBackground.GetWidth(), mBackground.GetHeight());
	Hunter::Renderer::Draw(mTitle, 100, 650, mTitle.GetWidth(), mTitle.GetHeight());
	Hunter::Renderer::Draw(mInstructions, 15, 550, mInstructions.GetWidth(), mInstructions.GetHeight());

	if (mGameEnd)
	{
		Hunter::Renderer::Draw(mGameOverMessage, 200, 350, mGameOverMessage.GetWidth(), mGameOverMessage.GetHeight());
		return;
	}
	 
	if (mFrameNumber % 45 == 0)
	{
		std::string smackableType{ "assets/smackable" + std::to_string(rand()%3 + 1) + ".png" };
		mSmackables.emplace_back(smackableType, 7); 

		int currSizeSmackables = mSmackables.size();

		mSmackables.back().SetYCoord(GameApp::GetWindowHeight());
		mSmackables.back().SetXCoord(rand() % (GameApp::GetWindowWidth() - mSmackables.back().GetWidth()));
	}

	if (mFlySwatterAction == Action::LeftMove)
	{
		if (mFlySwatter.GetXCoord() >= mFlySwatter.GetSpeed())
			mFlySwatter.UpdateXCoord(-mFlySwatter.GetSpeed());

		else
			mFlySwatter.SetXCoord(0);
	}

	else if (mFlySwatterAction == Action::RightMove)
	{
		if (mFlySwatter.GetXCoord() + mFlySwatter.GetWidth() + mFlySwatter.GetSpeed() <= GameApp::GetWindowWidth())
			mFlySwatter.UpdateXCoord(mFlySwatter.GetSpeed());

		else
			mFlySwatter.SetXCoord(GameApp::GetWindowWidth() - mFlySwatter.GetWidth());
	}

	while (!mSmackables.empty() && mSmackables.front().GetYCoord() <= -mSmackables.front().GetHeight())
		mSmackables.pop_front();

	for (auto& smackable : mSmackables)
	{
		smackable.UpdateYCoord(-smackable.GetSpeed());

		if (smackable.OverlapsWith(mFlySwatter) &&
			smackable.GetSpritePath() == "assets/smackable3.png" &&
			mFlySwatterAction == Action::Smack)
		{
			mGameEnd = true;
			std::cout << mScore << std::endl;
		}
			

		else if (smackable.OverlapsWith(mFlySwatter) &&
				 smackable.GetSpritePath() == "assets/smackable1.png" || smackable.GetSpritePath() == "assets/smackable2.png" &&
				 mFlySwatterAction == Action::Smack)
		{
			mScore++;
			mSmackables.pop_front();
		}
	}

	for (const auto& smackable : mSmackables)
		smackable.Draw();

	mFlySwatter.Draw();

	mFrameNumber++;
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent & event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
	{
		mFlySwatterAction = Action::LeftMove;
	}

	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
	{
		mFlySwatterAction = Action::RightMove;
	}

	else if (event.GetKeyCode() == HUNTER_KEY_SPACE)
	{
		mFlySwatterAction = Action::Smack;
	}
}

void GameApp::OnKeyReleased(Hunter::KeyReleasedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT || event.GetKeyCode() == HUNTER_KEY_RIGHT)
		mFlySwatterAction = Action::Forward;
}