#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
	public:
		Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

		void bind() const;
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
		unsigned int id() const;
	private:
		unsigned int compileShader(GLenum type, const char* source);
		unsigned int id_;
};

#endif //SHADER_H
