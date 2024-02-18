#pragma once

#include "OpenGLCore.h"
#include "../CoreWindow.h"

class OpenGLWindow : public CoreWindow
{
public:
	OpenGLWindow(uint32_t width, uint32_t height, const char* title);
	~OpenGLWindow();
	
	WindowType GetWindowType() const override { return GetStaticType(); }
	
	void SetEventCallback(const std::function<void(std::shared_ptr<Event>)>& eventCallbackFunction) override
		{ _windowData.eventCallbackFunction = eventCallbackFunction; }

	bool ShouldClose() const override;
	void WindowClose() override;
	void WindowInfo() const override;
	void WindowResize(uint32_t width, uint32_t height) override;
	void WindowClear() override;
	void OnUpdate() override;
	float GetCurrentFrameTime() override;

	static WindowType GetStaticType() { return WindowType::OPENGL_WINDOW; }

	struct OpenGLWindowData
	{
		uint32_t width, height;
		std::function<void(std::shared_ptr<Event>)> eventCallbackFunction;
	};

private:
	GLFWwindow*		 _window;
	OpenGLWindowData _windowData;

};