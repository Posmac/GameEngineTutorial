#pragma once

#ifdef RF_PLATFORM_WINDOWS
	#ifdef RF_BUILD_DLL
		#define RF_API __declspec(dllexport)
	#else
		#define RF_API __declspec(dllimport)
	#endif
#else
	#error Engine supports only Windows platform!
#endif

#define BIT(x) (1<<x)