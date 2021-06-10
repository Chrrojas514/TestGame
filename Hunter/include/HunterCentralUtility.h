#pragma once

/* for crossplatform, this section of ifdef should be within another ifdef determining if os is windows */

#ifdef _HUNTER_DLL_BUILD
	#define HUNTER_API __declspec(dllexport)
#else
	#define HUNTER_API __declspec(dllimport)
#endif

#ifdef _MY_DEBUG
	#define HLOG(x) std::cout << x << std::endl;
#else
	#define HLOG(x)
#endif