#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"

namespace Hunter
{
	void HunterApp::RunGame()
	{
		HLOG("Starting the game")

		while (true)    //collect player input, update game objects, render stuff, repeat
		{
			appWindow->SwapBuffers();
			appWindow->PollForEvents();
		}
	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}

	void HunterApp::Init()
	{
		if (instance == nullptr)
			instance = new HunterApp;
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow; 
#else
	#Only_windows_supported_for_now
#endif
		
		bool success{ appWindow->CreateWindow(800, 600) };
		assert(success);
	}

	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
	}
}