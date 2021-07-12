#include "Sprite.h"
#include <pch.h>
#include "stb_image.h"

namespace Hunter
{
	Sprite::Sprite(const std::string& spriteFile)
	{
		stbi_set_flip_vertically_on_load(true);

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

	const unsigned char* Sprite::GetImagePointer() const
	{
		return mImage;
	}

	Sprite::~Sprite()
	{
		stbi_image_free(mImage);
	}
}