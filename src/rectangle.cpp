#include "rectangle.h"

Rectangle::Rectangle(Point position, float width, float height, Color color)
	: RectangleParent(position, width, height, color)
	, shader_("src/res/shaders/rect.vs", "src/res/shaders/rect.fs")
	, translation_(1.0f)
	, transformLoc_(0)
{
	float colors[3] = {color.red(), color.green(), color.blue()};

	shader_.bind();
	unsigned int colorLocation = glGetUniformLocation(shader_.id(), "u_Color");
	glUniform3fv(colorLocation, 1, colors);

	transformLoc_ = glGetUniformLocation(shader_.id(), "u_translation");

}

Rectangle::~Rectangle()
{

}

void Rectangle::draw() const
{
	shader_.bind();
	glUniformMatrix4fv(transformLoc_, 1, GL_FALSE, glm::value_ptr(translation_));
	RectangleParent::draw();
}

float Rectangle::width() const
{
	return RectangleParent::width();
}

float Rectangle::height() const
{
	return RectangleParent::height();
}

float Rectangle::xPos() const
{
	return RectangleParent::xPos();
}

float Rectangle::yPos() const
{
	return RectangleParent::yPos();
}

void Rectangle::setWidth(const float& width)
{
	RectangleParent::setWidth(width);
}

void Rectangle::setHeight(const float& height)
{
	RectangleParent::setHeight(height);
}

void Rectangle::moveRight(const float& increment)
{
	translation_ = glm::translate(translation_, glm::vec3(increment, 0.0, 0.0));
	RectangleParent::moveRight(increment);
}

void Rectangle::moveUp(const float& increment)
{
	translation_ = glm::translate(translation_, glm::vec3(0.0, increment, 0.0));
	RectangleParent::moveUp(increment);
}
