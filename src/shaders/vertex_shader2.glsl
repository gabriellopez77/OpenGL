#version 330 core
layout (location = 0) in vec3 pos1;

void main()
{
	gl_Position = vec4(pos1.x, pos1.y, pos1.z, 1.25f);
};