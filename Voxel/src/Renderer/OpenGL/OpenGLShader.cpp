#pragma once

#include "OpenGLShader.h"

#include <fstream>

OpenGLShader::OpenGLShader(const std::string& shaderFileName)
	:_id(0), _fileName(shaderFileName), _shaderType(ShaderType::NONE)
{
	std::ifstream file(shaderFileName);
	std::string shaderSource;

	if (file.fail())
	{
		LOG_ERROR("Could not open shader source file: " + shaderFileName);
		return;
	}
	
	std::string buffer;
	while (std::getline(file, buffer))
	{
		if (buffer.find("#SHADER") != std::string::npos)
		{
			if (buffer.find("#SHADER VERTEX") != std::string::npos)
			{
				_shaderType = ShaderType::VERTEX_SHADER;

				_name = buffer.substr(strlen("#SHADER VERTEX"));
			}
			else if (buffer.find("#SHADER FRAGMENT") != std::string::npos)
			{
				_shaderType = ShaderType::FRAGMENT_SHADER;

				_name = buffer.substr(strlen("#SHADER FRAGMENT"));
			}
		}
		else
		{
			shaderSource += buffer;
			shaderSource += '\n';
		}
	}

	const char* shaderSourceStr = shaderSource.c_str();

	GLCALL(_id = glCreateShader((GLuint)_shaderType));
	GLCALL(glShaderSource(_id, 1, &shaderSourceStr, nullptr));
	GLCALL(glCompileShader(_id));
}

bool OpenGLShader::CompileSucess()
{
	int success;
	GLCALL(glGetShaderiv(_id, GL_COMPILE_STATUS, &success));

	if (!success)
	{
		char infoLog[256];
		GLCALL(glGetShaderInfoLog(_id, sizeof(infoLog), nullptr, infoLog));
		LOG_ERROR(std::string("Shader ") + _name + std::string(" from file '") + _fileName + 
			std::string("' did not compile: ") + std::string(infoLog));
	}

	return success;
}

OpenGLShader::~OpenGLShader()
{
	GLCALL(glDeleteShader(_id));
	_id = 0;
}



OpenGLShaderProgram::OpenGLShaderProgram()
	:_id(0), _linked(false)
{
	GLCALL(_id = glCreateProgram());
}


void OpenGLShaderProgram::Bind() const
{
	if (_linked)
	{
		GLCALL(glUseProgram(_id));
	}
	else
	{
		if (_linked = Link())
		{
			GLCALL(glUseProgram(_id));
		}
		else
		{
			Unbind();
			LOG_WARN("Shader Program not bound");
		}
	}
}

void OpenGLShaderProgram::Unbind() const
{
	GLCALL(glUseProgram(0));
}

bool OpenGLShaderProgram::AttachShader(std::shared_ptr<OpenGLShader> shader)
{
	if (shader->CompileSucess())
	{
		_attachedShaders.push_back(shader);
		GLCALL(glAttachShader(_id, shader->GetShaderId()));
		_linked = false;
		return true;
	}
	else
	{
		LOG_WARN(std::string("Shader ") + shader->GetName() + std::string(" from file '") + shader->GetFileName() + 
				std::string("' was not attached to Shader Program"));
		return false;
	}
}

bool OpenGLShaderProgram::AttachShader(const std::string& shaderFileName)
{
	std::shared_ptr<OpenGLShader> shader = std::make_shared<OpenGLShader>(shaderFileName);
	if (shader->CompileSucess())
	{
		_attachedShaders.push_back(shader);
		GLCALL(glAttachShader(_id, shader->GetShaderId()));
		_linked = false;
		return true;
	}
	else
	{
		LOG_WARN(std::string("Shader ") + shader->GetName() + std::string(" from file '") + shader->GetFileName() +
			std::string("' was not attached to Shader Program"));
		return false;
	}
}

static std::vector<std::shared_ptr<OpenGLShader>>::const_iterator 
	searchByName(const std::vector<std::shared_ptr<OpenGLShader>>& vec, const std::string& name)
{
	for (auto iter = vec.cbegin(); iter < vec.cend(); iter++)
	{
		if (iter->get()->GetName() == name)
			return iter;
	}
	return vec.cend();
}

void OpenGLShaderProgram::DettachShader(const std::string& shaderName)
{
	auto shader = searchByName(_attachedShaders, shaderName);
	GLCALL(glDetachShader(_id, shader->get()->GetShaderId()));
	_attachedShaders.erase(shader);
	_linked = false;
}

int32_t OpenGLShaderProgram::GetUniformLocation(const std::string& uniform) const
{
	const auto& iter = _uniformLocationCache.find(uniform);
	if (iter != _uniformLocationCache.cend())
		return iter->second;
	
	GLCALL(int32_t location = glGetUniformLocation(_id, uniform.c_str()));
	_uniformLocationCache[uniform] = location;
	return location;
}

void OpenGLShaderProgram::SetUniform4f(const std::string& uniform, const stm::vec4f& value) const
{
	GLCALL(glUniform4f(GetUniformLocation(uniform), value.x, value.y, value.z, value.w));
}

void OpenGLShaderProgram::SetUniformMat4f(const std::string& uniform, const stm::mat4f& value) const
{
	GLCALL(glUniformMatrix4fv(GetUniformLocation(uniform), 1, GL_TRUE, value.GetData()));
}

void OpenGLShaderProgram::SetUniform1i(const std::string& uniform, uint32_t value) const
{
	glUniform1i(GetUniformLocation(uniform), value);
}

bool OpenGLShaderProgram::Link() const
{
	GLCALL(glLinkProgram(_id));

	int success;
	GLCALL(glGetProgramiv(_id, GL_LINK_STATUS, &success));

	if (!success)
	{
		char infoLog[256];
		glGetProgramInfoLog(_id, sizeof(infoLog), nullptr, infoLog);
		LOG_ERROR(std::string("Shader Program did not link: ") + std::string(infoLog));
	}

	return success;
}

OpenGLShaderProgram::~OpenGLShaderProgram()
{
	GLCALL(glDeleteProgram(_id));
}