#pragma once

#include "OpenGLCore.h"

void OpenGLKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void OpenGLMouseMoveCallback(GLFWwindow* window, double xpos, double ypos);
void OpenGLWindowResizeCallback(GLFWwindow* window, int width, int height);
void OpenGLWindowCloseCallback(GLFWwindow* window);