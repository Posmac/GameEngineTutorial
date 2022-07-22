#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace rfe
{
	class RF_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	// To be defined in CLIENT
	Application* CreateApplication();
}