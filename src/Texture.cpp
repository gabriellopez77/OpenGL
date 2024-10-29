#include "Texture.h"

Texture::Texture(const char* texturePath) {
	stbi_set_flip_vertically_on_load(true);
	this->data = stbi_load(texturePath, &this->width, &this->height, &this->nrChannels, 0);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	float color[] = { 1.f, 1.f, 1.f, 1.f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (data == nullptr)
	{
		std::cout << "failed to load texture\n";
		return;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

int Texture::getWidth() const {
	return this->width;
}

int Texture::getHeight() const {
	return this->height;
}

unsigned char* Texture::getData() const {
	return this->data;
}

void Texture::free() const {
	stbi_image_free(this->data);
}