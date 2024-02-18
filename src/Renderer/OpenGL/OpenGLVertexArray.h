#pragma once

#include "OpenGLCore.h"

#include <vector>

struct OpenGLVertexElements
{
	uint32_t _type;
	uint32_t _count;
	uint8_t  _normalized;

	OpenGLVertexElements(uint32_t type, uint32_t count, uint8_t normalized)
		:_type(type), _count(count), _normalized(normalized) {}

	static size_t GetSizeOfType(uint32_t type)
	{
		switch (type)
		{
		case GL_FLOAT:
			return sizeof(GLfloat);
		case GL_UNSIGNED_INT:
			return sizeof(GLuint);
		case GL_UNSIGNED_BYTE:
			return sizeof(GLubyte);
		case GL_BOOL:
			return sizeof(GLboolean);
		default:
			LOG_WARN("Vertex Buffer Element not registered: (type)" + std::to_string(type));
			return 0;
		}
	}
};


class OpenGLVertexBufferLayout
{
public:
	template<typename T> void Push(uint32_t count);

	//template<> void Push<GLfloat>	(uint32_t count);
	//template<> void Push<GLuint>	(uint32_t count);
	//template<> void Push<GLubyte>	(uint32_t count);

	const std::vector<OpenGLVertexElements>& GetElements() const { return _elements; }
	uint32_t GetStride() const { return _stride; }
private:
	std::vector<OpenGLVertexElements> _elements;
	uint32_t _stride;
};


class OpenGLVertexArray
{
public:
	OpenGLVertexArray(const OpenGLVertexBufferLayout& layout);
	OpenGLVertexArray(const OpenGLVertexArray&) = delete;
	~OpenGLVertexArray();

	void Bind() const;
	void Unbind() const;
private:
	uint32_t _id;
	OpenGLVertexBufferLayout _layout;

private:
	void EnableAttributes() const;
};