#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <GL/glew.h>
#include <vector>
#include <iostream>
#include <algorithm>

class VertexBuffer
{
	public:
		VertexBuffer();
		VertexBuffer(const std::vector<float>& data, unsigned int vertexDataCount);

		VertexBuffer(const std::vector<float>& data, 
					 unsigned int vertexDataCount, 
					 const std::vector<int>& offsets);

		~VertexBuffer();

		void addIndex(const std::vector<float>& newIndexData, 
					  unsigned int indexDataCount);

		void bind() const;
		void unbind() const;

	private:
		void enableAttributes() const;
		std::vector<float> data_;
		std::vector<int> offsets_;
		unsigned int id_;
		unsigned int endOfIndex;
};

#endif //VERTEX_BUFFER_H
