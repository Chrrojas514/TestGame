#pragma once

#include "HunterCentralUtility.h"
#include "HunterApp.h"
#include "Sprite.h"
#include "Renderer.h"
#include "HunterKeys.h"


//Showcases singleton techniques

#define START_GAME(class_name)							\
	int main()											\
	{													\
		class_name* gamePointer = new class_name;		\
		gamePointer->GetApplication() -> RunGame();		\
		delete gamePointer;								\
	}

//Make sure the \ character is spaced away -- it denotes "not the end of the string"
//Make sure the \ character has NO NEW/EMPTY SPACES AFTER IT EITHER