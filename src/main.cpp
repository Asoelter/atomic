#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <vector>

#include "shader.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "element_buffer.h"
#include "texture.h"
#include "square.h"
#include "window.h"
#include "bordered_rectangle.h"

int main()
{
	Window window(800, 600, "Test");
	Rectangle rect(Point(0.0f, 0.0f), 0.5f, 0.5f, Color(Shade::RED));
	BorderedRectangle bRect(Point(-0.5f, -0.5f), 0.1f, 0.1f, Color(Shade::BLUE), Color(Shade::BLACK));

	while(window.open())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);

		rect.draw();
		bRect.draw();
		window.update();
	}

	return 0;
}
