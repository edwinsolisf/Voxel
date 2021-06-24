#pragma once

#include "OpenGLWindow.h"
#include "OpenGLCallback.h"
#include "stb/stb_image.h"

OpenGLWindow::OpenGLWindow(uint32_t width, uint32_t height, const char* title)
	:_width(width), _height(height), _title(title)
{
	if (!glfwInit())
	{
		throw; 
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(_width, _height, title, nullptr, nullptr);
	glfwMakeContextCurrent(_window);

	if (glewInit() != GLEW_OK)
	{
		throw;
	}

	LOG_INFO("GLFW " + std::string(glfwGetVersionString()));
	LOG_INFO("OpenGL " + std::string((char*)glGetString(GL_VERSION)));
	LOG_INFO((char*)glGetString(GL_VENDOR));
	LOG_INFO((char*)glGetString(GL_RENDERER));

	glViewport(0, 0, _width, _height); 

	GLFWimage icon;
	icon.pixels = stbi_load("assets/images/icon.png", &icon.width, &icon.height, nullptr, 4);
	glfwSetWindowIcon(_window, 1, &icon);
	stbi_image_free(icon.pixels);

	glfwSetKeyCallback(_window, key_callback);
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(_window, mouse_callback);
}

bool OpenGLWindow::ShouldClose() const
{
	return glfwWindowShouldClose(_window);
}

void OpenGLWindow::ProcessEvents() const
{
	movement(_window);
	GLCALL(glfwSwapBuffers(_window));
	GLCALL(glfwPollEvents());
}

void OpenGLWindow::Clear() const
{
	GLCALL(glEnable(GL_CULL_FACE));
	GLCALL(glCullFace(GL_FRONT));
	GLCALL(glEnable(GL_DEPTH_TEST));
	GLCALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	GLCALL(glClearColor(0.3f, 0.4f, 0.8f, 1.0f));
}

OpenGLWindow::~OpenGLWindow()
{
	glfwDestroyWindow(_window);
	_window = nullptr;
	glfwTerminate();
}