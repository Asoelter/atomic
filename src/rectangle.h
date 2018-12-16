#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "rectangle_parent.h"
#include "shader.h"

class Rectangle : public RectangleParent
{
	public:
		Rectangle(Point position, float width, float height, Color color);
		virtual ~Rectangle(); 		

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
		Shader			shader_;

};

#endif //RECTANGLE_H
