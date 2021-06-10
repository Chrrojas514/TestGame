#include <pch.h>
#include "HunterApp.h"

namespace Hunter
{
	void HunterApp::RunGame()
	{
		HLOG("Starting the game")

		while (true)    //collect player input, update game objects, render stuff, repeat
		{

		}
	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}

	void HunterApp::Init()
	{
		if (instance != nullptr)
			instance = new HunterApp;
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);
	}
}