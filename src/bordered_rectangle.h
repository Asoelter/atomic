#ifndef BORDERED_RECTANGLE_H
#define BORDERED_RECTANGLE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "rectangle_parent.h"
#include "shader.h"

class BorderedRectangle : public RectangleParent
{
	public:
		BorderedRectangle(Point position, float width, 
						  float height, Color color, Color borderColor);

		virtual void draw() const;

		virtual void moveRight(const float& increment);
		virtual void moveUp(const float& increment);


	private:
		void updateHorizontalBorderLimits() const;
		void updateVerticalBorderLimits()   const;

		Shader		shader_;
		glm::mat4	translation_;
		unsigned	transformLoc_;
};

#endif //BORDERED_RECTANGLE_H
