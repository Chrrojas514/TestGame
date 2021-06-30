#include <pch.h>
#include "HunterApp.h"
#include "Renderer.h"
#include "WindowsWindow.h"
#include "Sprite.h"

namespace Hunter
{
	void HunterApp::RunGame()
	{
		HLOG("Starting the game")

		Renderer::Init();

		Sprite testOne{ "../Hunter/assets/Sprites/face.png" };
		Sprite testTwo{ "../Hunter/assets/Sprites/fish.png" };


		while (true)    //collect player input, update game objects, render stuff, repeat
		{
			Renderer::Draw(testOne, 100, 100, testOne.GetWidth(), testOne.GetHeight());
			Renderer::Draw(testTwo, 100, 100, testTwo.GetWidth(), testTwo.GetHeight());

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

	int HunterApp::GetWindowWidth()
	{
		return instance->appWindow->GetWidth();
	}

	int HunterApp::GetWindowHeight()
	{
		return instance->appWindow->GetHeight();
	}
}