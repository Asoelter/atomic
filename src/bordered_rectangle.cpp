#include "bordered_rectangle.h"

BorderedRectangle::BorderedRectangle(Point position, float width, float height, Color color, Color borderColor)
	: RectangleParent(position, width, height, color)
	, shader_("src/res/shaders/bordered_rect.vs", "src/res/shaders/bordered_rect.fs")
	, translation_(1.0f)
	, transformLoc_(0)
{
	float colors[3] = {color.red(), color.green(), color.blue()};

	shader_.bind();
	unsigned int colorLocation = glGetUniformLocation(shader_.id(), "u_Color");
	glUniform3fv(colorLocation, 1, colors);

	float borderColors[3] = {borderColor.red(), borderColor.green(), borderColor.blue()};

	shader_.bind();
	unsigned int borderColorLocation = glGetUniformLocation(shader_.id(), "u_BorderColor");
	glUniform3fv(borderColorLocation, 1, borderColors);

	updateHorizontalBorderLimits();
	updateVerticalBorderLimits();

	transformLoc_ = glGetUniformLocation(shader_.id(), "u_translation");
}

void BorderedRectangle::draw() const
{
	shader_.bind();
	glUniformMatrix4fv(transformLoc_, 1, GL_FALSE, glm::value_ptr(translation_));
	RectangleParent::draw();
}

float BorderedRectangle::width() const
{
	return RectangleParent::width();
}

float BorderedRectangle::height() const
{
	return RectangleParent::height();
}

float BorderedRectangle::xPos() const
{
	return RectangleParent::xPos();
}

float BorderedRectangle::yPos() const
{
	return RectangleParent::yPos();
}

void BorderedRectangle::setWidth(const float& width)
{
	RectangleParent::setWidth(width);
}

void BorderedRectangle::setHeight(const float& height)
{
	RectangleParent::setHeight(height);
}

void BorderedRectangle::moveRight(const float& increment)
{
	translation_ = glm::translate(translation_, glm::vec3(increment, 0.0, 0.0));
	RectangleParent::moveRight(increment);
	updateHorizontalBorderLimits();
}

void BorderedRectangle::moveUp(const float& increment)
{
	translation_ = glm::translate(translation_, glm::vec3(0.0, increment, 0.0));
	RectangleParent::moveUp(increment);
	updateVerticalBorderLimits();
}

void BorderedRectangle::updateHorizontalBorderLimits() const
{
	float xMaxLimit			= RectangleParent::xPos() + (RectangleParent::width()  / 2);
	float xMinLimit			= RectangleParent::xPos() - (RectangleParent::width()  / 2);
	float xMaxBorderLimit	= 0;
	float xMinBorderLimit	= 0;

	if(xMaxLimit > 0.0f)
	{
		xMaxBorderLimit = xMaxLimit + (0.05 * RectangleParent::width());
	}
	else 
	{
		xMaxBorderLimit = xMaxLimit - (0.05 * RectangleParent::width());
	}

	if(xMinLimit > 0.0f)
	{
		xMinBorderLimit = xMinLimit - (0.05 * RectangleParent::width());
	}
	else
	{
		xMinBorderLimit = xMinLimit + (0.05 * RectangleParent::width());
	}

	shader_.setFloat("xMax", xMaxBorderLimit);
	shader_.setFloat("xMin", xMinBorderLimit);
}

void BorderedRectangle::updateVerticalBorderLimits() const
{
	float yMaxLimit			= RectangleParent::yPos() + (RectangleParent::height() / 2);
	float yMinLimit			= RectangleParent::yPos() - (RectangleParent::height() / 2);
	float yMaxBorderLimit	= 0;
	float yMinBorderLimit	= 0;

	if(yMaxLimit > 0.0f)
	{
		yMaxBorderLimit = yMaxLimit + (0.05 * RectangleParent::height());
	}
	else
	{
		yMaxBorderLimit = yMaxLimit - (0.05 * RectangleParent::height());
	}

	if(yMinLimit > 0.0f)
	{
		yMinBorderLimit = yMinLimit - (0.05 * RectangleParent::height());
	}
	else
	{
		yMinBorderLimit = yMinLimit + (0.05 * RectangleParent::height());
	}

	shader_.setFloat("yMax", yMaxBorderLimit);
	shader_.setFloat("yMin", yMinBorderLimit);
}
