#include "rectangle_parent.h"

RectangleParent::RectangleParent(Point position, float width, float height, Color color)
	: vao_()
	, vbo_()
	, position_(position)
	, width_(width)
	, height_(height)
	, color_(color)
{
	std::vector<float> positions = {
		(position.x() - (width / 2)) , (position.y() - (height / 2)) , 0.0f,
		(position.x() - (width / 2)) , (position.y() + (height / 2)) , 0.0f,
		(position.x() + (width / 2)) , (position.y() + (height / 2)) , 0.0f,

		(position.x() + (width / 2)) , (position.y() + (height / 2)) , 0.0f,
		(position.x() + (width / 2)) , (position.y() - (height / 2)) , 0.0f,
		(position.x() - (width / 2)) , (position.y() - (height / 2)) , 0.0f
	};

	vbo_.addIndex(positions, 3);
}

void RectangleParent::draw()   const
{
	vao_.bind();
	vbo_.bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

float RectangleParent::width()   const
{
	return width_;
}

float RectangleParent::height()  const
{
	return height_;
}

float RectangleParent::xPos()    const
{
	return position_.x();
}

float RectangleParent::yPos()    const
{
	return position_.y();
}

void RectangleParent::setWidth (const float& width)
{
	width_ = width;
}

void RectangleParent::setHeight(const float& height)
{
	height_ = height;
}

void RectangleParent::moveRight(const float& increment)
{
	position_.x(position_.x() + increment);
}

void RectangleParent::moveUp   (const float& increment)
{
	position_.y(position_.y() + increment);
}
