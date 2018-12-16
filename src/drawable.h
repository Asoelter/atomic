#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "vertex_array.h"

class Drawable
{
	public:
		virtual ~Drawable() {}

		virtual void draw() const = 0;

	private:
		//Drawable()								= delete;
		//Drawable(const Drawable&)				= delete;
		//Drawable& operator=(const Drawable&)	= delete;
};

#endif //DRAWABLE_H
