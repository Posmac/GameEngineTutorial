#include "rfpch.h"
#include "Application.h"

namespace rfe
{
	Application::Application(){

	}

	Application::~Application(){

	}

	void Application::Run()
	{
		WindowResizeEvent wnd(1920, 1080);
		if (wnd.IsInCategory(EventCategory::ApplicationCategory))
		{
			RF_CLIENT_WARN(wnd);
		}
		if (wnd.IsInCategory(EventCategory::InputCategory))
		{
			RF_CLIENT_ERROR(wnd);
		}
		while (true);
	}
}
