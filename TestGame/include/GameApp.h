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
	Unit mFlySwatter;
	std::deque<Unit> mSmackables;

	Hunter::Sprite mTitle;
	Hunter::Sprite mInstructions;
	Hunter::Sprite mGameOverMessage;
	Hunter::Sprite mBackground;

	enum class Action
	{
		LeftMove,
		RightMove,
		Forward,
		Smack
	} mFlySwatterAction;

	int mScore;
	bool mGameEnd;
	long long mFrameNumber;
};