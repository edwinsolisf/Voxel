#pragma once

#include "OpenGLVertexBuffer.h"

OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, size_t size)
	:_id(0)
{
	GLCALL(glGenBuffers(1, &_id));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _id));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

void OpenGLVertexBuffer::Bind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _id));
}

void OpenGLVertexBuffer::Unbind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	GLCALL(glDeleteBuffers(1, &_id));
}