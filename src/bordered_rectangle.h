#ifndef BORDERED_RECTANGLE_H
#define BORDERED_RECTANGLE_H

#include "rectangle_parent.h"
#include "shader.h"

class BorderedRectangle : public RectangleParent
{
	public:
		BorderedRectangle(Point position, float width, 
						  float height, Color color, Color borderColor);

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
		void updateHorizontalBorderLimits() const;
		void updateVerticalBorderLimits() const;
		Shader shader_;
};

#endif //BORDERED_RECTANGLE_H
