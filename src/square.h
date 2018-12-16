#ifndef SQUARE_H
#define SQUARE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "rectangle.h"
#include "color.h"

struct Square : public Rectangle
{
	Square(Point position, float width, Color color);
};

#endif //SQUARE_H
