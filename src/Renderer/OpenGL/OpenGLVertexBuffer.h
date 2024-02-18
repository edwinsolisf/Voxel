#pragma once

#include "OpenGLCore.h"

class OpenGLVertexBuffer
{
public:
	OpenGLVertexBuffer(const void* data, size_t size);

	OpenGLVertexBuffer(const OpenGLVertexBuffer&) = delete;

	~OpenGLVertexBuffer();

	void Bind() const;
	void Unbind() const;

private:
	uint32_t _id;
};