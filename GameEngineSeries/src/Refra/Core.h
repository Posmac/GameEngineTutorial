#pragma once

#ifdef RF_PLATFORM_WINDOWS
	#ifdef RE_BUILD_DLL
		#define RE_API __declspec(dllexport)
	#else
		#define RE_API __declspec(dllimport)
	#endif
#else
	#error Engine supports only Windows platform!
#endif