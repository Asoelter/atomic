#include "window.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->keys_[key] = action != GLFW_RELEASE;
}

Window::Window(unsigned int width, unsigned int height, const std::string& title)
	: keys_()
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

	glfwSetKeyCallback(window_, keyCallback);

	glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
	glfwSetWindowUserPointer(window_, this);
}

Window::~Window()
{
	glfwDestroyWindow(window_);
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
	glClear(GL_COLOR_BUFFER_BIT);

	if(glfwGetKey(window_, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window_, true);
	}
}

void Window::setBackGroundColor(Color c)
{
	glClearColor(c.red(), c.green(), c.blue(), 1.0f);
}

bool Window::keyIsPressed(Key key)
{
	return keys_[static_cast<int>(key)];
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

