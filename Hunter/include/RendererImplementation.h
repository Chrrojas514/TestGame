#pragma once

#include "Sprite.h"

namespace Hunter
{
	class RendererImplementation
	{
	public:
		virtual void Init() = 0;
		virtual void Draw(const Sprite& image, int xCoord, int yCoord, int imageWidth, int imageHeight) = 0;
		virtual void ClearFrame() = 0;
		virtual ~RendererImplementation() = 0 {};
	};
}