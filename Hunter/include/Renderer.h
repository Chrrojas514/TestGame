#pragma once

#include "Sprite.h"
#include "RendererImplementation.h"

namespace Hunter
{
	class Renderer
	{
	public:
		static void Init();
		static void ShutDown();
		static void Draw(const Sprite &image, int xCoord, int yCoord, int imageWidth, int imageHeight);
	private:
		Renderer();

		inline static Renderer* instance{ nullptr };
		RendererImplementation* mDrawingEngine{ nullptr };
	};
}