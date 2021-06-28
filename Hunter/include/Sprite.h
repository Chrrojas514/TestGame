#pragma once

#include "HunterCentralUtility.h"
#include <pch.h>

namespace Hunter
{
	class HUNTER_API Sprite
	{
	public:
		Sprite(const std::string& spriteFile);
		~Sprite();

		bool Load(const std::string& spriteFile);

		int GetWidth() const;
		int GetHeight() const;

	private:
		unsigned char* mImage = nullptr; 
		int mWidth = 0;
		int mHeight = 0;
		int mNumChannels = 0;
	};
}