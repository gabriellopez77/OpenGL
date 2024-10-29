#version 330 core
layout (location = 0) in vec3 pos1;

uniform float xOffset;
uniform float yOffset;

void main()
{
	gl_Position = vec4(pos1.x + xOffset, pos1.y + yOffset, pos1.z, 1.0);
};