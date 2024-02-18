#pragma once

#include "OpenGL/OpenGLWindow.h"
#include "OpenGL/OpenGLVertexArray.h"
#include "OpenGL/OpenGLVertexBuffer.h"
#include "OpenGL/OpenGLIndexBuffer.h"
#include "OpenGL/OpenGLRender.h"
#include "OpenGL/OpenGLShader.h"
#include "OpenGL/OpenGLTexture.h"

#ifdef OPENGL_ENGINE
	using Window = OpenGLWindow;
	using VertexArray = OpenGLVertexArray;
	using VertexBuffer = OpenGLVertexBuffer;
	using VertexBufferLayout = OpenGLVertexBufferLayout;
	using IndexBuffer = OpenGLIndexBuffer;
	using Shader = OpenGLShaderProgram;
	using Texture = OpenGLTexture;
#else
	#error "No engine defined"
#endif