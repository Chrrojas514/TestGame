#include <pch.h>
#include "HunterApp.h"
#include "Renderer.h"
#include "WindowsWindow.h"
#include "Sprite.h"
#include "HunterKeys.h"

namespace Hunter
{
	void HunterApp::RunGame()
	{
		HLOG("Starting the game")

		Renderer::Init();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)    //collect player input, update game objects, render stuff, repeat
		{
			Renderer::ClearFrame();

			//Will be central tool for game programmer -- where programmer specifies what should be done on each run of 
			//the game loop
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			appWindow->SwapBuffers();
			appWindow->PollForEvents();

			mNextFrameTime += mFrameDuration;
		}
	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

		instance = this; //lose ability to create single hunterapp object ourselves 

#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow; 
#else
	#Only_windows_supported_for_now
#endif
		
		bool success{ appWindow->CreateWindow(800, 800) };
		assert(success);

		appWindow->SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});

		appWindow->SetKeyReleasedCallback([this](KeyReleasedEvent& event) {
			OnKeyReleased(event);
			});
	}

	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
	}

	void HunterApp::OnUpdate()
	{
		//HunterApp does not do anything with this function, game programmer will use/define this
	}

	int HunterApp::GetWindowWidth()
	{
		return instance->appWindow->GetWidth();
	}

	int HunterApp::GetWindowHeight()
	{
		return instance->appWindow->GetHeight();
	}

	void HunterApp::OnKeyPressed(KeyPressedEvent& event)
	{ }

	void HunterApp::OnKeyReleased(KeyReleasedEvent & event)
	{ }
}