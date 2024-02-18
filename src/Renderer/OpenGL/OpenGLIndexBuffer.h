#pragma once

#include "OpenGLCore.h"

class OpenGLIndexBuffer
{
public:
	OpenGLIndexBuffer(const uint32_t* data, uint32_t indexCount);
	~OpenGLIndexBuffer();

	OpenGLIndexBuffer(const OpenGLIndexBuffer&) = delete;

	void Bind() const;
	void Unbind() const;

	uint32_t GetIndexCount() const { return _indexCount; }

private:
	uint32_t _id;
	uint32_t _indexCount;
};