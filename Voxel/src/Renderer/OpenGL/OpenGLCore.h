#pragma once

#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"

#include "GLFW/glfw3.h"

#include "../../Utilities/Logging.h"

#ifdef DEBUG
    #include "stm/debug.h"
    #define GLCALL(x)   GLClearError();\
                        x;\
                        stm_assert(!GLCheckError(#x, __FILE__, __LINE__))
#else
    #define GLCALL(x) x
#endif

static const char* GLError(int error)
{
    switch (error)
    {
    case GL_INVALID_ENUM:
        return "GL_INVALID_ENUM";
    case GL_INVALID_OPERATION:
        return "GL_INVALID_OPERATION";
    case GL_INVALID_VALUE:
        return "GL_INVALID_VALUE";
    case GL_STACK_OVERFLOW:
        return "GL_STACK_OVERFLOW";
    case GL_STACK_UNDERFLOW:
        return "GL_STACK_UNDERFLOW";
    case GL_OUT_OF_MEMORY:
        return "GL_OUT_OF_MEMORY";
    default:
        return "";
    }
}

static bool InitializedGLFW = false;
static bool InitializedGLEW = false;

static bool InitializeGLFW()
{
    return (glfwInit() == GLFW_TRUE);
}

static bool InitializeGLEW()
{
    return (glewInit() == GLEW_OK);
}

static void GLClearError()
{
    while ((glGetError() != GL_NO_ERROR) && InitializedGLEW && InitializedGLFW);
}

static bool GLCheckError(const char* function, const char* file, int line)
{
    bool state = false;
    GLenum error = glGetError();
    while (error && InitializedGLEW && InitializedGLFW)
    {
        state = true;
        std::cout << "[OPENGL ERROR](function: " << function << ", file: " << file << ", " << ", line: " << line << "): " << GLError(error) << std::endl;
    }
    return state;
}