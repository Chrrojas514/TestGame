#include "..\include\Unit.h"
#include "Hunter.h"

Unit::Unit(const std::string& spritePath, int newSpeed): spriteLocation(spritePath), mImage(spritePath), mSpeed(newSpeed)
{ }

void Unit::SetXCoord(int newX)
{
	mXcoord = newX;
}

void Unit::SetYCoord(int newY)
{
	mYcoord = newY;
}

int Unit::GetXCoord() const
{
	return mXcoord;
}

int Unit::GetYCoord() const
{
	return mYcoord;
}

int Unit::GetWidth() const
{
	return mImage.GetWidth();
}

int Unit::GetHeight() const
{
	return mImage.GetHeight();
}

int Unit::GetSpeed() const
{
	return mSpeed;
}

std::string Unit::GetSpritePath() const
{
	return spriteLocation;
}

void Unit::UpdateXCoord(int changeX)
{
	mXcoord += changeX;
}

void Unit::UpdateYCoord(int changeY)
{
	mYcoord += changeY;
}

void Unit::Draw() const
{
	Hunter::Renderer::Draw(mImage, mXcoord, mYcoord, mImage.GetWidth(), mImage.GetHeight());
}


//improve this
bool Unit::OverlapsWith(const Unit& other) const
{
	if ((mXcoord <= other.mXcoord && other.mXcoord <= mXcoord + GetWidth()) ||
		(mXcoord <= other.mXcoord + other.GetWidth() && other.mXcoord + other.GetWidth() <= mXcoord + GetWidth()))
	{
		if (mYcoord <= other.mYcoord ||
			mYcoord <= other.mYcoord + other.GetHeight() && other.mYcoord + other.GetHeight() <= mYcoord + GetHeight())

			return true;
	}

	return false;
}
