#include "OpenGLCallback.h"

#include "OpenGLWindow.h"
#include "../../EventSystem/WindowEvent.h"
#include "../../EventSystem/MouseEvent.h"
#include "../../EventSystem/KeyEvent.h"

void OpenGLKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	OpenGLWindow::OpenGLWindowData& data = *static_cast<OpenGLWindow::OpenGLWindowData*>(glfwGetWindowUserPointer(window));

	switch (action)
	{
	case GLFW_PRESS:
		data.eventCallbackFunction(std::make_shared<KeyPressedEvent>((KeyCode)key));
		break;

	case GLFW_RELEASE:
		data.eventCallbackFunction(std::make_shared<KeyReleasedEvent>((KeyCode)key));
		break;

	case GLFW_REPEAT:
		data.eventCallbackFunction(std::make_shared<KeyRepeatEvent>((KeyCode)key));
		break;
	}
}

void OpenGLMouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
{
	OpenGLWindow::OpenGLWindowData& data = *static_cast<OpenGLWindow::OpenGLWindowData*>(glfwGetWindowUserPointer(window));

	data.eventCallbackFunction(std::make_shared<MouseMovedEvent>(xpos, ypos));
}

void OpenGLWindowResizeCallback(GLFWwindow* window, int width, int height)
{
	OpenGLWindow::OpenGLWindowData& data = *static_cast<OpenGLWindow::OpenGLWindowData*>(glfwGetWindowUserPointer(window));
	data.width = width;
	data.height = height;

	data.eventCallbackFunction(std::make_shared<WindowResizeEvent>(width, height));
}

void OpenGLWindowCloseCallback(GLFWwindow* window)
{
	OpenGLWindow::OpenGLWindowData& data = *static_cast<OpenGLWindow::OpenGLWindowData*>(glfwGetWindowUserPointer(window));
	data.eventCallbackFunction(std::make_shared<WindowCloseEvent>());
}