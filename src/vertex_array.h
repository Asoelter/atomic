#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <GL/glew.h>
#include <iostream>

class VertexArray
{
	public:
		VertexArray();
		~VertexArray();
		void bind() const;
		void unbind() const;
		unsigned int id() const;
	private:
		unsigned int id_;
};

#endif //VERTEX_ARRAY_H
