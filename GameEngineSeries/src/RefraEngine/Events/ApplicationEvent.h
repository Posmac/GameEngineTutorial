#pragma once

#include "Event.h"

#include <sstream>

namespace rfe
{
	class RF_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width (width), m_Height(height)
		{}

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }
		
		std::string  ToString() const override
		{
			std::ostringstream ss;
			ss << "Windows Resize Event: " << m_Width << " : " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(ApplicationCategory)

	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class RF_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};

	class RF_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};

	class RF_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};

	class RF_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};
}