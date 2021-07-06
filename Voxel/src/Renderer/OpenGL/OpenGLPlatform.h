#pragma once

#include "../../Platform/Platform.h"

#ifdef PLATFORM_WINDOWS
	#define GLEW_STATIC
	#include "GL/glew.h"
	#include "GLFW/glfw3.h"

#elif PLATFORM_APPLE
	#include "GLFW/glfw3.h"
	#include <OpenGL/gl.h>
	#include <OpenGL/gl3.h>

#else
	#error OpenGL not supported for the given platform

#endif