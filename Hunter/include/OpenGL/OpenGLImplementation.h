#pragma once

#include "RendererImplementation.h"
#include "OpenGL/OpenGLShader.h"

namespace Hunter
{
	class OpenGLImplementation : public RendererImplementation
	{
	public:
		OpenGLImplementation();
		virtual void Init() override;
		virtual void Draw(const Sprite& image, int xCoord, int yCoord, int imageWidth, int imageHeight) override;
		virtual void ClearFrame() override;
		virtual ~OpenGLImplementation();

	private:
		OpenGLShader mDefaultShader;
	};
}