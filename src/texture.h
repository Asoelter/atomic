#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <string>
#include <iostream>

#include <stb/stb_image.h>

class Texture
{
	public:
		Texture(const std::string& filePath);
		void bind() const;
		void unbind() const;

	private:
		unsigned int id_;
		unsigned int textureNumber_;
		static int textureCount_;
};

#endif //TEXTURE_H
