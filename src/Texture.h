#pragma once

#include "GLTemplates.h"
#include <stb_image.h>

class Texture {
public:
	Texture(const char* texturePath);

	unsigned char* getData() const;
	int getWidth() const;
	int getHeight() const;

	void free() const;

private:
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
};