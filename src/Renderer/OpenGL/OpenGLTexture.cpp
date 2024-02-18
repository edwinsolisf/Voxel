#include "OpenGLTexture.h"

#include "stb/stb_image.h"

OpenGLTexture::OpenGLTexture(const std::string& textureFile)
	:_id(0), _width(0), _height(0), _file(textureFile), _buffer(nullptr)
{
	_buffer = stbi_load(textureFile.c_str(), &_width, &_height, nullptr, 4);

	if (!_buffer)
	{
		LOG_ERROR("Failed to load texture image file: " + textureFile);
		return;
	}

	GLCALL(glGenTextures(1, &_id));
	GLCALL(glBindTexture(GL_TEXTURE_2D, _id));
	GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _buffer));

	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT));
	
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

	GLCALL(glGenerateMipmap(GL_TEXTURE_2D));

	stbi_image_free(_buffer);
	_buffer = nullptr;
}

void OpenGLTexture::Bind(uint32_t slot) const
{
	GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
	GLCALL(glBindTexture(GL_TEXTURE_2D, _id));
}

void OpenGLTexture::Unbind() const
{
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

OpenGLTexture::~OpenGLTexture()
{
	GLCALL(glDeleteTextures(1, &_id));
}