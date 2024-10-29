#version 330 core

layout (location = 0) in vec3 pos1;

void main()
{
	gl_Position = vec4(pos1.x +1.25f, pos1.y -1.25f, pos1.z, 2.f);
};