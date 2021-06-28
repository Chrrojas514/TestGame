#pragma once

#include "HunterCentralUtility.h"
#include "HunterApp.h"


#define START_GAME(class_name)							\
	int main()											\
	{													\
		class_name::Init();								\
		class_name::GetApplication() -> RunGame();		\
	}