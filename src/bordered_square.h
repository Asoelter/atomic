#ifndef BORDERED_SQAURE_H
#define BORDERED_SQAURE_H

#include "bordered_rectangle.h"

struct BorderedSquare : public BorderedRectangle
{
	BorderedSquare(Point position, float width, Color color, Color borderColor);
};

#endif //BORDERED_SQUARE_H
