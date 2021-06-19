#pragma once

#include "OpenGLIndexBuffer.h"

OpenGLIndexBuffer::OpenGLIndexBuffer(const uint32_t* data, uint32_t indexCount)
	:_id(0), _indexCount(indexCount)
{
	GLCALL(glGenBuffers(1, &_id));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id));
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(uint32_t), data, GL_STATIC_DRAW));
}

void OpenGLIndexBuffer::Bind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id));
}

void OpenGLIndexBuffer::Unbind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	GLCALL(glDeleteBuffers(1, &_id));
}