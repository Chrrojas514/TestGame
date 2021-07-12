#include<pch.h>
#include "WindowsWindow.h"

namespace Hunter
{
	bool WindowsWindow::CreateWindow(unsigned int width, unsigned int height)
	{
		glfwInit();

		window = glfwCreateWindow(width, height, "The Buggy Game", NULL, NULL);

		if (window == nullptr)
			return false;

		glfwMakeContextCurrent(window);
		gladLoadGL();

		glfwSwapInterval(1);

		glfwSetWindowUserPointer(window, &mCallbacks);

		//lambda function -- [](params) {func}
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == GLFW_PRESS || action == GLFW_REPEAT)
			{
				KeyPressedEvent event{ key };

				Callbacks* callbacks = (Callbacks*)glfwGetWindowUserPointer(window);

				callbacks->keyPressedCallback(event);
			}

			else if (action == GLFW_RELEASE)
			{
				KeyReleasedEvent event{ key };

				Callbacks* callback{ (Callbacks*)glfwGetWindowUserPointer(window) };
				callback->keyReleasedCallback(event);
			}
			});

		return true;
	}

	void WindowsWindow::DeleteWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void WindowsWindow::SwapBuffers()
	{
		glfwSwapBuffers(window);
	}

	void WindowsWindow::PollForEvents()
	{
		glfwPollEvents();
	}

	int WindowsWindow::GetWidth() const
	{
		int width = 0;
		int height = 0;
		glfwGetWindowSize(window, &width, &height);

		return width;
	}

	int WindowsWindow::GetHeight() const
	{
		int width = 0;
		int height = 0;
		glfwGetWindowSize(window, &width, &height);

		return height;
	}

	void WindowsWindow::SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback)
	{
		mCallbacks.keyPressedCallback = newCallback;
	}

	void WindowsWindow::SetKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback)
	{
		mCallbacks.keyReleasedCallback = newCallback;
	}
}