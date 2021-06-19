#pragma once

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	Apptick, AppUpdate, 
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

class Event
{
public:
	virtual ~Event() = default;

	virtual EventType GetEventType() = 0;
	virtual const char* GetName() = 0;

	bool _handled = false;
};

class EventDispatcher
{
public:
	EventDispatcher(Event& event)
		:_event(event)
	{
	}
private:
};

class EventHandler
{

};