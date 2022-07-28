#pragma once

#include "RefraEngine/Core.h"

namespace rfe
{
	class RF_API Input
	{
	public:
		inline static bool IsKeyPressed(int keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(int mouseCode) { return s_Instance->IsMouseButtonPressedImpl(mouseCode); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int keymouseCode) = 0;
		virtual std::pair<float,float> GetMousePositionImpl() = 0;
	private:
		static Input* s_Instance;
	};
}