#pragma once

#include "OpenGLCore.h"

#include <string>
#include <vector>
#include <unordered_map>
#include "stm/math.h"

enum class ShaderType
{
	NONE = -1,
	VERTEX_SHADER = GL_VERTEX_SHADER,
	FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

class OpenGLShader
{
public:
	OpenGLShader(const std::string& shaderFileName);
	OpenGLShader(const OpenGLShader&) = delete;
	~OpenGLShader();

	bool CompileSucess();

	uint32_t GetShaderId() const { return _id; }
	const std::string& GetName() const { return _name; }
	const std::string& GetFileName() const { return _fileName; }
	ShaderType GetShaderType() const { return _shaderType; }

private:
	uint32_t _id;
	std::string _fileName;
	std::string _name;
	ShaderType _shaderType;
};

class OpenGLShaderProgram
{
public:
	OpenGLShaderProgram();
	~OpenGLShaderProgram();

	bool AttachShader(std::shared_ptr<OpenGLShader> shader);
	bool AttachShader(const std::string& shaderFileName);
	void DettachShader(const std::string& shader);

	void Bind() const;
	void Unbind() const;

	int32_t GetUniformLocation(const std::string& uniform) const;
	
	void SetUniform4f(const std::string& uniform, const stm::vec4f& value) const;
	void SetUniformMat4f(const std::string& uniform, const stm::mat4f& value) const;
	void SetUniform1i(const std::string& uniform, uint32_t value) const;

private:
	uint32_t _id;
	mutable bool _linked;

	std::vector<std::shared_ptr<OpenGLShader>> _attachedShaders;
	mutable std::unordered_map<std::string, int32_t> _uniformLocationCache;

private:
	bool Link() const;
};
