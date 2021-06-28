#pragma once

#include "Shader.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hunter
{
	class OpenGLShader : public Shader
	{
	public:
		virtual bool Load(const std::string& vertexFile, const std::string& fragmentFile) override;
		virtual void Use() override;

		virtual void SetVec2Int(const std::string& uniformName, int valueOne, int valueTwo) override;
		~OpenGLShader() override;

	private:
		unsigned int mShaderProgram{ 0 };

		unsigned int CompileVertexShader(const std::string& vertexCode);
		unsigned int CompileFragmentShader(const std::string& fragmentCode);
	};
}