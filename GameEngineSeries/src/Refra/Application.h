#pragma once

#include "Core.h"

namespace rfe
{
	class RE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	// To be defined in CLIENT
	Application* CreateApplication();
}