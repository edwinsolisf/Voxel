#pragma once

#include <memory>
#include <functional>

#include "../EventSystem/Event.h"

enum class WindowType
{
	OPENGL_WINDOW
};

class CoreWindow
{
public:
	uint32_t GetWidth() const { return _width; }
	uint32_t GetHeight() const { return _height; }
	const char* GetTitle() const { return _title; }

protected:
	CoreWindow(uint32_t width, uint32_t height, const char* title)
		:_width(width), _height(height), _title(title) {}

	virtual ~CoreWindow() {};
	virtual WindowType GetWindowType() const = 0;
	virtual void SetEventCallback(const std::function<void(std::shared_ptr<Event>)>& eventCallbackFunction) = 0;

	virtual bool ShouldClose() const = 0;
	virtual void WindowClose() = 0;
	virtual void WindowInfo() const = 0;
	virtual void WindowResize(uint32_t width, uint32_t height) = 0;
	virtual void WindowClear() = 0;

	uint32_t _width;
	uint32_t _height;
	const char* _title;
};