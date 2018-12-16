#ifndef ELEMENT_BUFFER_H
#define ELEMENT_BUFFER_H

#include <GL/glew.h>
#include <vector>

class ElementBuffer
{
	public:
		ElementBuffer(std::vector<unsigned int> elements);
		~ElementBuffer();
		
		void bind() const;
		void unbind() const;

	private:
		unsigned int id_;
};

#endif //ELEMENT_BUFFER_H
