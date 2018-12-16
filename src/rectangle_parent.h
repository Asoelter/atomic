#ifndef RECTANGLE_PARENT_H
#define RECTANGLE_PARENT_H

#include "point.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "color.h"

class RectangleParent
{
	protected:
		RectangleParent(Point position, float width, float height, Color color);

		virtual void  draw()    const;

		virtual float width()   const;
		virtual float height()  const;
		virtual float xPos()    const;
		virtual float yPos()    const;

		virtual void  setWidth (const float& width);
		virtual void  setHeight(const float& height);
		virtual void  moveRight(const float& increment);
		virtual void  moveUp   (const float& increment);

	private:
		VertexArray		vao_;
		VertexBuffer	vbo_;
		Point			position_;
		float			width_;
		float			height_;
		Color			color_;

};

#endif //RECTANGLE_PARENT_H
