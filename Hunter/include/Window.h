#pragma once

#include "pch.h"
#include "HunterCentralUtility.h"
#include "KeyboardEvents.h"

namespace Hunter
{
	/* For cross platform combatibilty, make WindowsWindow, MacWindow, LinuxWindow class etc or use macros within Createwindow function */
	class Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) = 0;
		virtual void DeleteWindow() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollForEvents() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent &)> newCallback) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback) = 0;
	};
}