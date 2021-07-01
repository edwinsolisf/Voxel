#pragma once

#include "Event.h"

class WindowEvent : public Event
{
protected:
	WindowEvent() {}

public:
	static EventType GetStaticType() { return EventType::Window; }

	virtual EventType GetEventType() const override { return GetStaticType(); }
	virtual const char* GetName() const override { return "WindowEvent"; }
	virtual std::string ToString() const override { return GetName(); }
};

class WindowCloseEvent : public WindowEvent
{
public:
	WindowCloseEvent() {}
	static EventType GetStaticType() { return EventType::WindowClose; }

	EventType GetEventType() const override { return GetStaticType(); }
	const char* GetName() const override { return "WindowCloseEvent"; }
	std::string ToString() const override { return GetName(); }
};

class WindowResizeEvent : public WindowEvent
{
public:
	WindowResizeEvent(uint32_t width, uint32_t height) :_width(width), _height(height) {}
	static EventType GetStaticType() { return EventType::WindowResize; }

	EventType GetEventType() const override { return GetStaticType(); }
	const char* GetName() const override { return "WindowResizeEvent"; }
	std::string ToString() const override { return GetName(); }

	uint32_t GetWidth() const { return _width; }
	uint32_t GetHeight() const { return _height; }

private:
	uint32_t _width, _height;
};