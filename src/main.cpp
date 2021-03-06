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
#include "bordered_square.h"

int main()
{
	Window window(800, 600, "Test");
	Rectangle rect(Point(0.0f, 0.0f), 0.5f, 0.5f, Color(Shade::RED));
	BorderedRectangle bRect(Point(0.0f, 0.0f), 0.3f, 0.3f, Color(Shade::GREEN), Color(Shade::BLACK));
	BorderedSquare square(Point(0.1f, 0.1f), 0.2f, Color(Shade::BLACK), Color(Shade::WHITE));

	while(window.open())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);

		if(window.keyIsPressed(Key::LEFT_ARROW_KEY))
		{
			bRect.moveRight(-0.01f);
		}
		else if(window.keyIsPressed(Key::RIGHT_ARROW_KEY))
		{
			bRect.moveRight(0.01f);
		}

		rect.draw();
		bRect.draw();
		square.draw();
		window.update();
	}

	return 0;
}
