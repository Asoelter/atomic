#include "shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vsin;
	std::ifstream fsin;

	vsin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fsin.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vsin.open(vertexPath);
		fsin.open(fragmentPath);

		std::stringstream vShaderStream;
		std::stringstream fShaderStream;

		vShaderStream << vsin.rdbuf();
		fShaderStream << fsin.rdbuf();

		vsin.close();
		fsin.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;

	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int vertex = compileShader(GL_VERTEX_SHADER, vShaderCode);
	unsigned int fragment = compileShader(GL_FRAGMENT_SHADER, fShaderCode);

	id_ = glCreateProgram();
	glAttachShader(id_, vertex);
	glAttachShader(id_, fragment);
	glLinkProgram(id_);

	int success = 0;
	glGetProgramiv(id_, GL_LINK_STATUS, &success);
	if(!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(id_, 512, NULL, infoLog);
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::bind() const
{
	glUseProgram(id_);
}

void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const 
{
	glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}

unsigned int Shader::id() const
{
	return id_;
}

unsigned int Shader::compileShader(GLenum type, const char* source)
{
	unsigned int id = glCreateShader(type);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);

	int success = 0;
	char infoLog[512];

	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if(!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER" 
				  << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") 
				  << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	return id;
}
