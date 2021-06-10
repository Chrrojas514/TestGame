#pragma once
#include<HunterCentralUtility.h>

namespace Hunter
{
	class HUNTER_API HunterApp
	{
	public:
		void RunGame();
		static HunterApp* GetApplication();   //Should be called without having to create an object first (why its static)
		static void Init();
	private:
		HunterApp();
		inline static HunterApp* instance{ nullptr };
	};
}