#define STB_IMAGE_IMPLEMENTATION
#include "texture.h"

int Texture::textureCount_ = 0;

Texture::Texture(const std::string& filePath)
	: id_(0)
	, textureNumber_(textureCount_)
{
	int width = 0;
	int height = 0;
	int numChannels = 0;

	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &numChannels, 0);

	glGenTextures(1, &id_);
	glBindTexture(GL_TEXTURE_2D, id_);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if(data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Unable to load texture" << std::endl;
	}

	stbi_image_free(data);
	++textureCount_;
}

void Texture::bind() const
{
	glActiveTexture(GL_TEXTURE0 + textureNumber_);
	glBindTexture(GL_TEXTURE_2D, id_);
}

void Texture::unbind() const
{
	glActiveTexture(GL_TEXTURE0 + textureNumber_);
	glBindTexture(GL_TEXTURE_2D, 0);
}
