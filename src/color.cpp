#include "color.h"

Color::Color(float red, float green, float blue)
	: red_(red)
	, green_(green)
	, blue_(blue)
{

}

Color::Color(Shade shade)
	: red_(0.0f)
	, green_(0.0f)
	, blue_(0.0f)
{
	switch(shade)
	{
		case Shade::RED:
			red_ = 1.0f;
		break;
		case Shade::GREEN:
			green_ = 1.0f;
		break;
		case Shade::BLUE:
			blue_ = 1.0f;
		break;
		case Shade::BLACK:
			red_	= 0.0f;
			green_	= 0.0f;
			blue_	= 0.0f;
		break;
		default:
			red_	= 1.0f;
			green_	= 1.0f;
			blue_	= 1.0f;
		break;
	}
}

void Color::setRed(float red)
{
	red_ = red;
}

void Color::setGreen(float green)
{
	green_ = green;
}

void Color::setBlue(float blue)
{
	blue_ = blue;
}

float Color::red() const
{
	return red_;
}

float Color::green() const
{
	return green_;
}

float Color::blue() const
{
	return blue_;
}
