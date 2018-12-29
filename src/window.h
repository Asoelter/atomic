#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <unordered_map>

#include "color.h"

enum class Key
{
	UP_ARROW_KEY	= GLFW_KEY_UP,
	RIGHT_ARROW_KEY = GLFW_KEY_RIGHT,
	DOWN_ARROW_KEY  = GLFW_KEY_DOWN,
	LEFT_ARROW_KEY  = GLFW_KEY_LEFT
};

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

		bool keyIsPressed(Key key);

	private:
		GLFWwindow* window_;
		std::unordered_map<unsigned, bool> keys_;

	private: //callbacks
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		friend void keyCallback(GLFWwindow* window, int key, 
								   int scancode, int action, int mods);
};

#endif //WINDOW_H
