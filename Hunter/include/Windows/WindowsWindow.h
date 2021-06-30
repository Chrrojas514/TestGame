#pragma once

#include "HunterCentralUtility.h"
#include "Window.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Hunter
{
	class WindowsWindow final : public Hunter::Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) override;
		virtual void DeleteWindow() override;
		virtual void SwapBuffers() override;
		virtual void PollForEvents() override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
	private:
		GLFWwindow* window;
	};
}