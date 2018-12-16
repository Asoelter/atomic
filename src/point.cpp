#include "point.h"

Point::Point(float x, float y)
	: x_(x)
	, y_(y)
{

}

bool Point::operator==(const Point& other)
{
	return x_ == other.x_ && y_ == other.y_;
}

float Point::x() const
{
	return x_;
}

float Point::y() const
{
	return y_;
}

void Point::x(const float x)
{
	x_ = x;
}

void Point::y(const float y)
{
	y_ = y;
}
