#pragma once

#include "Hunter.h"

class Unit
{
public:
	Unit(const std::string& spritePath, int newSpeed);

	void SetXCoord(int newX);
	void SetYCoord(int newY);

	int GetXCoord() const;
	int GetYCoord() const;

	int GetWidth() const;
	int GetHeight() const;

	int GetSpeed() const;

	void UpdateXCoord(int changeX);
	void UpdateYCoord(int changeY);

	void Draw() const;

	bool OverlapsWith(const Unit& other) const;

	Unit(const Unit&) = delete; //disable copy constructor
	Unit(Unit&&) = delete; //disable move constructor
	Unit& operator=(const Unit&) = delete; //disable copy operation
	Unit& operator=(Unit&&) = delete; //disable move operation

private:
	Hunter::Sprite mImage;

	int mXcoord;
	int mYcoord;
	int mSpeed;

};