#include <pch.h>
#include "HunterApp.h"
#include "OpenGL/OpenGLImplementation.h"

namespace Hunter
{
	OpenGLImplementation::OpenGLImplementation()
	{
		Init();
	}

	void OpenGLImplementation::Init()
	{
		mDefaultShader.Load(
			"../Hunter/assets/shaders/VertexShaderDefault.glsl",
			"../Hunter/assets/shaders/FragmentShaderDefault.glsl"
		);

		mDefaultShader.Use();

		glEnable(GL_BLEND);
		//					  source					target
		//				(1.0, 0.0, 0.0, 0.7)     (0.0, 1.0, 0.0, 1.0)
		//									BLEND
		//    (1.0 * 0.7 + 0.0*(1-0.7), 0.0*0.7+1.0*(1-0.7),  0.0*0.7+0.0*(1-0.7), XXXXX)

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLImplementation::Draw(const Sprite& image, int xCoord, int yCoord, int imageWidth, int imageHeight)
	{
		float vertices[] = {
			(float)xCoord				, (float)yCoord				   , 0.0f, 0.0f,
			(float)xCoord				, (float)(yCoord + imageHeight), 0.0f, 1.0f,
			(float)(xCoord + imageWidth), (float)(yCoord)			   , 1.0f, 0.0f,
			(float)(xCoord + imageWidth), (float)(yCoord + imageHeight), 1.0f, 1.0f   
		};

		unsigned int VBO, VAO;

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int picture;

		glGenTextures(1, &picture);
		glBindTexture(GL_TEXTURE_2D, picture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetImagePointer());

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//hardcoded? no...?
		mDefaultShader.SetVec2Int("windowSize", HunterApp::GetWindowWidth(), HunterApp::GetWindowHeight());

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); //problem involves this line
	}

	OpenGLImplementation::~OpenGLImplementation() {}
}