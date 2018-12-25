#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

#include "color.h"

class Window
{
	public:
		Window(unsigned int width, unsigned int height, const std::string& title);
		~Window();

		GLFWwindow* glfwWindow();
		bool open()   const;
		void close()  const;
		void update() const;
		void setBackGroundColor(Color c);

	private:
		GLFWwindow* window_;

	private: //callbacks
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif //WINDOW_H
