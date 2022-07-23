#pragma once

#include "rfpch.h"
#include "Event.h"

namespace rfe
{
	class RF_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{}
		
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Moused moved event: " << m_MouseX << " | " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(MouseCategory | InputCategory)
	private:
		float m_MouseX;
		float m_MouseY;
	};

	class RF_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset)
			: m_OffsetX(xOffset), m_OffsetY(yOffset)
		{}

		inline float GetX_Offset() const { return m_OffsetX; }
		inline float GetY_Offset() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Moused scrolla event: " << m_OffsetX << " | " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(MouseCategory | InputCategory)
	private:
		float m_OffsetX;
		float m_OffsetY;
	};

	class RF_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(MouseCategory | InputCategory)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		int m_Button;
	};

	class RF_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Moused button pressed event: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class RF_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Moused button released event: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}