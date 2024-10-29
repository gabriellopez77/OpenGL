#pragma once

#include "../includes/glad/glad.h"
#include <GLFW/glfw3.h>

class Shader
{
public:
	unsigned int ID = 0;

	Shader(const char*, const char*);

	void use() const;

	void setBool(const char*, bool) const;
	void setInt(const char*, int) const;
	void setFloat(const char*, float) const;
};
