#pragma once
#include "OpenGLVertexArray.h"

template<>
void OpenGLVertexBufferLayout::Push<GLfloat>(uint32_t count)
{
	_elements.emplace_back(GL_FLOAT, count, GL_FALSE);
	_stride += OpenGLVertexElements::GetSizeOfType(GL_FLOAT) * count;
}

template<>
void OpenGLVertexBufferLayout::Push<GLuint>(uint32_t count)
{
	_elements.emplace_back(GL_UNSIGNED_INT, count, GL_FALSE);
	_stride += OpenGLVertexElements::GetSizeOfType(GL_UNSIGNED_INT) * count;
}

template<> 
void OpenGLVertexBufferLayout::Push<GLubyte>(uint32_t count)
{
	_elements.emplace_back(GL_UNSIGNED_BYTE, count, GL_TRUE);
	_stride += OpenGLVertexElements::GetSizeOfType(GL_UNSIGNED_BYTE);
}

OpenGLVertexArray::OpenGLVertexArray(const OpenGLVertexBufferLayout& layout)
	:_id(0), _layout(layout)
{
	GLCALL(glGenVertexArrays(1, &_id));
	GLCALL(glBindVertexArray(_id));
}

void OpenGLVertexArray::Bind() const
{
	GLCALL(glBindVertexArray(_id));
	EnableAttributes();
}

void OpenGLVertexArray::Unbind() const
{
	GLCALL(glBindVertexArray(0));
}

void OpenGLVertexArray::EnableAttributes() const
{
	const auto& elements = _layout.GetElements();
	uint32_t offset = 0;
	for (uint32_t i = 0; i < elements.size(); ++i)
	{
		const auto& element = elements[i];
		GLCALL(glVertexAttribPointer(i, element._count, element._type, element._normalized, _layout.GetStride(), (const void*)offset));
		GLCALL(glEnableVertexAttribArray(i));
		offset += element._count * element.GetSizeOfType(element._type);
	}
}

OpenGLVertexArray::~OpenGLVertexArray()
{
	GLCALL(glDeleteVertexArrays(1, &_id));
}