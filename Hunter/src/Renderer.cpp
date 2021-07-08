#include <pch.h>
#include "Renderer.h"
#include "OpenGL\OpenGLImplementation.h"

namespace Hunter
{
	void Renderer::Init()
	{
		if (instance == nullptr)
			instance = new Renderer;
	}
	
	void Renderer::ShutDown()
	{
		if (instance != nullptr)
			delete instance;
	}

	void Renderer::Draw(const Sprite& image, int xCoord, int yCoord, int imageWidth, int imageHeight)
	{
		assert(instance != nullptr);

		instance->mDrawingEngine->Draw(image, xCoord, yCoord, imageWidth, imageHeight);
	}

	void Renderer::ClearFrame()
	{
		instance->mDrawingEngine->ClearFrame();
	}

	Renderer::Renderer()
	{
	#ifdef _HUNTER_OPENGL
		mDrawingEngine = new OpenGLImplementation;

	#else
		#only_OpenGL_is_supported_atm
	#endif
	}
}