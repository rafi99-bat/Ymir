#pragma once

#ifdef YM_PLATFORM_WINDOWS
	#ifdef YM_BUILD_DLL
		#define YMIR_API __declspec(dllexport)
	#else
		#define YMIR_API __declspec(dllimport)
	#endif
#else
	#error The Engine only supports Windows
#endif // YM_PLATFORM_WINDOWS
