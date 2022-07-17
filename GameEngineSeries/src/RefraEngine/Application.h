#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace rfe
{
	class RF_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	// To be defined in CLIENT
	Application* CreateApplication();
}