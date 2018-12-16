#include "vertex_buffer.h"

VertexBuffer::VertexBuffer()
	: data_()
	, offsets_()
	, id_(0)
	, endOfIndex(0)
{
	glGenBuffers(1, &id_);
}

VertexBuffer::VertexBuffer(const std::vector<float>& data, unsigned int vertexDataCount)
	: data_(data)
	, offsets_()
	, id_(0)
	, endOfIndex(0)
{
	glGenBuffers(1, &id_);
	glBindBuffer(GL_ARRAY_BUFFER, id_);
	glBufferData(GL_ARRAY_BUFFER, data_.size() * sizeof(float), data_.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, vertexDataCount, GL_FLOAT, GL_FALSE, vertexDataCount* sizeof(float), 0);
	glEnableVertexAttribArray(0);

	offsets_.push_back(0);
	endOfIndex = vertexDataCount;
}

VertexBuffer::VertexBuffer(const std::vector<float>& data, 
						   unsigned int vertexDataCount, 
						   const std::vector<int>& offsets)
							: data_(data)
							, offsets_(offsets)
							, id_(0)
							, endOfIndex(0)
{
	glGenBuffers(1, &id_);
	glBindBuffer(GL_ARRAY_BUFFER, id_);
	glBufferData(GL_ARRAY_BUFFER, data_.size() * sizeof(float), data_.data(), GL_STATIC_DRAW);

	endOfIndex = vertexDataCount;
	enableAttributes();

}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id_);
}

void VertexBuffer::addIndex(const std::vector<float>& newIndexData, unsigned int indexDataCount)
{
	unsigned int totalSize = data_.size() + newIndexData.size();
	std::vector<float> newData;

	unsigned int indexElement		= 0;
	unsigned int currentOldElement	= 0;
	unsigned int currentNewElement	= 0;

	for(unsigned int i = 0; i < totalSize; ++i)
	{
		if(indexElement < endOfIndex)
		{
			newData.push_back(data_[currentOldElement]);
			++currentOldElement;
			++indexElement;
		}
		else if(indexElement >= endOfIndex && indexElement < endOfIndex + indexDataCount)
		{
			newData.push_back(newIndexData[currentNewElement]);
			++currentNewElement;
			++indexElement;
		}

		if(indexElement + 1 > endOfIndex + indexDataCount)
		{
			indexElement = 0;
		}
	}

	data_ = newData;
	glBindBuffer(GL_ARRAY_BUFFER, id_);
	glBufferData(GL_ARRAY_BUFFER, data_.size() * sizeof(float), data_.data(), GL_STATIC_DRAW);

	offsets_.push_back(endOfIndex);
	endOfIndex += indexDataCount;
	enableAttributes();
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void VertexBuffer::unbind() const 
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::enableAttributes() const
{
	unsigned int indexDataCount = 0;

	for(unsigned int i = 0; i < offsets_.size(); ++i)
	{
		if(i < offsets_.size() - 1)
		{
			indexDataCount = offsets_[i + 1] - offsets_[i];
		}
		else 
		{
			indexDataCount = endOfIndex - offsets_.back();
		}

		glVertexAttribPointer(i, indexDataCount, GL_FLOAT, GL_FALSE, 
							  endOfIndex * sizeof(float), (void*)(offsets_[i] * sizeof(float)));

		glEnableVertexAttribArray(i);
	}

}
