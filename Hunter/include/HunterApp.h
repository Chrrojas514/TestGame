#pragma once
#include "HunterCentralUtility.h"
#include "Window.h"
#include "KeyboardEvents.h"
#include <chrono>

namespace Hunter
{
	class HUNTER_API HunterApp
	{
	public:
		virtual void RunGame();
		static HunterApp* GetApplication();   //Should be called without having to create an object first (why its static)
		virtual ~HunterApp();

		virtual void OnUpdate();

		static int GetWindowWidth();
		static int GetWindowHeight();

		virtual void OnKeyPressed(KeyPressedEvent& event);
		virtual void OnKeyReleased(KeyReleasedEvent& event);

	protected: //derived classes are allowed to use this protected constructor
		HunterApp();

	private:
		inline static HunterApp* instance{ nullptr };

		Hunter::Window* appWindow{ nullptr };

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ 16 };  //can be replaced by mFrameDuration = std::milli{16};
	};
}