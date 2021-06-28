#include "Sprite.h"
#include "stb_image.h"

namespace Hunter
{
	Sprite::Sprite(const std::string& spriteFile)
	{
		if (!Load(spriteFile))
			HLOG("ERROR LOADING SPRITES")


	}

	bool Sprite::Load(const std::string& spriteFile)
	{
		mImage = stbi_load(spriteFile.c_str(), &mWidth, &mHeight, &mNumChannels, 0);

		if (mImage)
			return true;
		else
			return false;
	}

	int Sprite::GetWidth() const
	{
		return mWidth;
	}

	int Sprite::GetHeight() const
	{
		return mHeight; 
	}

	Sprite::~Sprite()
	{
		stbi_image_free(mImage);
	}
}