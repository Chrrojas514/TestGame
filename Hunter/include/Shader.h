#pragma once

#include <string>
#include "HunterCentralUtility.h"

namespace Hunter
{
	class HUNTER_API Shader
	{
	public:
		virtual bool Load(const std::string &vertexFile, const std::string &fragmentFile) = 0;
		virtual void Use() = 0;

		virtual void SetVec2Int(const std::string& uniformName, int valueOne, int valueTwo) = 0;
		virtual ~Shader() = 0 {};
	};
}