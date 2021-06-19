#pragma once

#include "OpenGLCore.h"

class OpenGLWindow
{
public:
	OpenGLWindow(uint32_t width, uint32_t height, const char* title);
	~OpenGLWindow();

	uint32_t GetWidth() const { return _width; }
	uint32_t GetHeight() const { return _height; }
	const char* GetTitle() const { return _title; }

	bool ShouldClose() const;
	//void Run() const;
	void Clear() const;
	void ProcessEvents() const;

private:
	uint32_t	_width;
	uint32_t	_height;
	const char* _title;

	GLFWwindow* _window;
};