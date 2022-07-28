#include "rfpch.h"
#include "WindowsInput.h"

#include "RefraEngine/Application.h"
#include "GLFW/glfw3.h"

namespace rfe
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto wnd = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(wnd, keycode);
		return state == GLFW_PRESS ||  state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int keymouseCode)
	{
		auto wnd = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(wnd, keymouseCode);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto wnd = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(wnd, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}
}