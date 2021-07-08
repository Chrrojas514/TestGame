#pragma once

#include <Hunter.h>
#include "Unit.h"
#include <deque>

/*
* CURRENTLY NO ASSETS/ASSETS WITH VALID NAMES
*/

class GameApp : public Hunter::HunterApp
{
public:
	GameApp();

	virtual void OnUpdate() override;

	virtual void OnKeyPressed(Hunter::KeyPressedEvent& event) override;
	virtual void OnKeyReleased(Hunter::KeyReleasedEvent& event) override;

private:
	Unit mSpaceship;
	std::deque<Unit> mPlanets;

	Hunter::Sprite mGameOverMessage;
	Hunter::Sprite mBackground;

	enum class Action
	{
		LeftMove,
		RightMove,
		Forward
	} mSpaceshipAction;

	bool mGameEnd;
	long long mFrameNumber;
};