#pragma once

#include <string>
#include "HunterCentralUtility.h"

namespace Hunter
{
	class HUNTER_API Sprite
	{
	public:
		Sprite(const std::string& spriteFile);				//constructor
		~Sprite();											//destructor

		Sprite(const Sprite& other) = delete;               //Copy constructor -- = delete means Sprite class cannot use this
		Sprite(Sprite&& other) = delete;					//Move constructor
		Sprite& operator==(const Sprite& other) = delete;   //Assignment operator 
		Sprite& operator=(Sprite&& other) = delete;			//Move operator

		bool Load(const std::string& spriteFile);

		int GetWidth() const;
		int GetHeight() const;
		const unsigned char* GetImagePointer() const;

	private:
		unsigned char* mImage = nullptr; 
		int mWidth = 0;
		int mHeight = 0;
		int mNumChannels = 0;
	};
}