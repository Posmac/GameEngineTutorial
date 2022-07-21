#include "rfpch.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace rfe
{
	Application::Application(){
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application(){

	}

	void Application::Run()
	{
		WindowResizeEvent wnd(1920, 1080);
		if (wnd.IsInCategory(EventCategory::ApplicationCategory))
		{
			while (m_Running)
			{
				glClearColor(1, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				m_Window->OnUpdate();
			}
		}
		
		while (true);
	}
}
