#include "vertex_array.h"

VertexArray::VertexArray()
	: id_(0)
{
	glGenVertexArrays(1, &id_);
	glBindVertexArray(id_);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &id_);
}

void VertexArray::bind() const
{
	glBindVertexArray(id_);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

unsigned int VertexArray::id() const
{
	return id_;
}
