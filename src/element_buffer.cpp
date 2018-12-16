#include "element_buffer.h"

ElementBuffer::ElementBuffer(std::vector<unsigned int> elements)
	: id_(0)
{
	glGenBuffers(1, &id_);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(unsigned int), elements.data(), GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer()
{
	glDeleteBuffers(1, &id_);
}

void ElementBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void ElementBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

