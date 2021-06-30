#include "OpenGL/OpenGLShader.h"
#include <pch.h>

namespace Hunter
{
	bool OpenGLShader::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		std::ifstream vertexSource{ vertexFile };
		std::ifstream fragmentSource{ fragmentFile };

		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertexSource.rdbuf();
		fShaderStream << fragmentSource.rdbuf();

		vertexSource.close();
		fragmentSource.close();

		std::string vertexCode = vShaderStream.str();
		std::string fragmentCode = fShaderStream.str();

		unsigned int vertexShader = CompileVertexShader(vertexCode);
		if (!vertexShader)
			return false;

		unsigned int fragmentShader = CompileFragmentShader(fragmentCode);
		if (!fragmentShader)
			return false;

		if (mShaderProgram)
			glDeleteProgram(mShaderProgram);

		mShaderProgram = glCreateProgram();

		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		int success = 0;
		char infoLog[512];

		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			HLOG("ERROR::LINKING::SHADERS")
			HLOG(infoLog)

			return false;
		}

		return true;
	}

	void OpenGLShader::Use()
	{
		assert(mShaderProgram);

		glUseProgram(mShaderProgram);
	}

	OpenGLShader::~OpenGLShader()
	{
		if (mShaderProgram)
			glDeleteProgram(mShaderProgram);
	}

	void OpenGLShader::SetVec2Int(const std::string& uniformName, int valueOne, int valueTwo)
	{
		assert(mShaderProgram);

		int uniformID{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(uniformID, valueOne, valueTwo);
	}

	unsigned int OpenGLShader::CompileVertexShader(const std::string& vertexCode)
	{
		unsigned int vertexShader;
		const char* cstring_vertexCode = vertexCode.c_str();

		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cstring_vertexCode, NULL);
		glCompileShader(vertexShader);

		int success = 0;
		char infoLog[512];

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			HLOG("VERT::SHADER::COMPILATION::ERROR")
		}

		return vertexShader;
	}

	unsigned int OpenGLShader::CompileFragmentShader(const std::string& fragmentCode)
	{
		unsigned int fragmentShader;
		const char* cstring_fragmentCode = fragmentCode.c_str();

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cstring_fragmentCode, NULL);
		glCompileShader(fragmentShader);

		int success = 0;
		char infoLog[512];

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			HLOG("ERROR::FRAG::SHADER::COMPILATION")
		}

		return fragmentShader;
	}
}