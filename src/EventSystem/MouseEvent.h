#pragma once

#include "Event.h"

class MouseEvent : public Event
{
protected:
	MouseEvent() {}

public:
	static EventType GetStaticType() { return EventType::Mouse; }

	virtual EventType GetEventType() const override { return GetStaticType(); }
	virtual const char* GetName() const override { return "MouseEvent"; }
	virtual std::string ToString() const override { return GetName(); }
};

class MouseMovedEvent : public MouseEvent
{
public:
	MouseMovedEvent(double x, double y) :_x(x), _y(y) {}
	static EventType GetStaticType() { return EventType::MouseMoved; }

	EventType GetEventType() const override { return GetStaticType(); }
	const char* GetName() const override { return "MouseMovedEvent"; }
	std::string ToString() const override { return GetName(); }

	double GetPosX() const { return _x; }
	double GetPosY() const { return _y; }

private:
	double _x, _y;
};

class MouseButtonPressed : public MouseEvent
{
public:
	MouseButtonPressed(uint32_t button) : _button(button) {}
	static EventType GetStaticType() { return EventType::MouseButtonPressed; }

	EventType GetEventType() const override { return GetStaticType(); }
	const char* GetName() const override { return "MouseButtonPressed"; }
	std::string ToString() const override { return GetName(); }

private:
	uint32_t _button;
};