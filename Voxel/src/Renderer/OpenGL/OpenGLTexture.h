#pragma once

#include "OpenGLCore.h"

class OpenGLTexture
{
public:
	OpenGLTexture(const std::string& textureFile);
	~OpenGLTexture();

	//OpenGLTexture(const OpenGLTexture&) = delete;
	OpenGLTexture(OpenGLTexture&& other) noexcept
	{
		_id = std::exchange(other._id, 0);
		_width = std::exchange(other._width, 0);
		_height = std::exchange(other._height, 0);
		_file = std::exchange(other._file, "");
		_buffer = std::exchange(other._buffer, nullptr);
	}

	//OpenGLTexture& operator=(const OpenGLTexture&) = delete;
	OpenGLTexture& operator=(OpenGLTexture&& other) noexcept
	{
		_id = std::exchange(other._id, 0);
		_width = std::exchange(other._width, 0);
		_height = std::exchange(other._height, 0);
		_file = std::exchange(other._file, "");
		_buffer = std::exchange(other._buffer, nullptr);
	}
	
	void Bind(uint32_t slot = 0) const;
	void Unbind() const;

private:
	uint32_t _id;
	int32_t _width;
	int32_t _height;

	std::string _file;
	void* _buffer;
};