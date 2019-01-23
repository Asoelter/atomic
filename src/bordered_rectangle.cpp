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
	unsigned borderColorLocation = glGetUniformLocation(shader_.id(), "u_BorderColor");
	glUniform3fv(borderColorLocation, 1, borderColors);

	updateHorizontalBorderLimits();
	updateVerticalBorderLimits();

	transformLoc_   = glGetUniformLocation(shader_.id(), "u_translation");
}

void BorderedRectangle::draw() const
{
	shader_.bind();
	glUniformMatrix4fv(transformLoc_, 1, GL_FALSE, glm::value_ptr(translation_));
	RectangleParent::draw();
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
	float xMaxLimit	= RectangleParent::xPos() + (RectangleParent::width()  / 2);
	float xMinLimit	= RectangleParent::xPos() - (RectangleParent::width()  / 2);

	//float xMaxBorderLimit = xMaxLimit - (0.05 * RectangleParent::width());
	//float xMinBorderLimit = xMinLimit + (0.05 * RectangleParent::width());

	float xMaxBorderLimit = xMaxLimit - 0.007;
	float xMinBorderLimit = xMinLimit + 0.007;

	shader_.bind();
	shader_.setFloat("xMax", xMaxBorderLimit);
	shader_.setFloat("xMin", xMinBorderLimit);
}

void BorderedRectangle::updateVerticalBorderLimits() const
{
	float yMaxLimit	= RectangleParent::yPos() + (RectangleParent::height() / 2);
	float yMinLimit	= RectangleParent::yPos() - (RectangleParent::height() / 2);

	//float yMaxBorderLimit = yMaxLimit - (0.05 * RectangleParent::height());
	//float yMinBorderLimit = yMinLimit + (0.05 * RectangleParent::height());

	float yMaxBorderLimit = yMaxLimit - 0.007;
	float yMinBorderLimit = yMinLimit + 0.007;

	shader_.bind();
	shader_.setFloat("yMax", yMaxBorderLimit);
	shader_.setFloat("yMin", yMinBorderLimit);
}
