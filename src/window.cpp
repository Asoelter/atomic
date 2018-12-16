#include "window.h"

Window::Window(unsigned int width, unsigned int height, const std::string& title)
{
	if(!glfwInit())
	{
		std::cout << "Unable to initialize GLFW\n";
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window_ = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window_);

	if(!window_)
	{
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
	}

	glewExperimental = GL_TRUE;

	if(glewInit() != GLEW_OK)
	{
		std::cout << "Unable to initialize GLEW\n";
	}
	glGetError();

	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
}

Window::~Window()
{
	glfwTerminate();
}

GLFWwindow* Window::glfwWindow()
{
	return window_;
}

bool Window::open()  const
{
	return !glfwWindowShouldClose(window_);
}

void Window::close() const
{
	glfwSetWindowShouldClose(window_, true);
}

void Window::update() const
{
	glfwSwapBuffers(window_);
	glfwPollEvents();

	if(glfwGetKey(window_, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window_, true);
	}
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
