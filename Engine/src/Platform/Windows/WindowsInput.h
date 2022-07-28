#pragma once

#include "RefraEngine/Input.h"

namespace rfe
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int keymouseCode) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
	};
}