#pragma once

#include "Event.h"
#include "KeyCodes.h"

class KeyEvent : public Event
{
public:
	static EventType GetStaticType() { return EventType::Key; }

	virtual EventType GetEventType() const override { return GetStaticType(); }
	virtual const char* GetName() const override { return "KeyEvent"; }
	virtual std::string ToString() const override { return GetName(); }


	KeyCode GetKeyCode() const { return _key; }
protected:
	KeyEvent(KeyCode key) :_key(key) {}

	KeyCode _key;
};

class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(KeyCode key) : KeyEvent(key) {}
	static EventType GetStaticType() { return EventType::KeyPressed; }

	EventType GetEventType() const override { return GetStaticType(); }
	const char* GetName() const override { return "KeyPressed"; }
	std::string ToString() const override { return GetName(); }
};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(KeyCode key) :KeyEvent(key) {}

	static EventType GetStaticType() { return EventType::KeyReleased; }

	EventType GetEventType() const override { return GetStaticType(); }
	const char* GetName() const override { return "KeyReleased"; }
	std::string ToString() const override { return GetName(); }

};

class KeyRepeatEvent : public KeyEvent
{
public:
	KeyRepeatEvent(KeyCode key) :KeyEvent(key) {}

	static EventType GetStaticType() { return EventType::KeyRepeat; }

	EventType GetEventType() const override { return GetStaticType(); }
	const char* GetName() const override { return "KeyRepeat"; }
	std::string ToString() const override { return GetName(); }
};
