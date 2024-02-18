#pragma once

#include <functional>
#include <string>

enum class EventType
{
	None = 0,
	Window, WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	Apptick, AppUpdate, 
	Key, KeyPressed, KeyReleased, KeyRepeat,
	Mouse, MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

class Event
{
protected:
	Event() {}

public:
	virtual ~Event() = default;

	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual std::string ToString() const = 0;

	bool _handled = false;
};

class EventDispatcher
{
public:
	EventDispatcher(Event& event)
		:_event(event)
	{
	}

	template<typename T>
	bool Dispatch(std::function<bool(T&)> func)
	{
		if (_event.GetEventType() == T::GetStaticType())
		{
			_event._handled = func(dynamic_cast<T&>(_event));
			return true;
		}
		return false;
	}

private:
	Event& _event;
};