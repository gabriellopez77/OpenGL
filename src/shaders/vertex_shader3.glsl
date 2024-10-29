#version 330 core

layout (location = 0) in vec3 pos1;
layout (location = 1) in vec3 vertColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 aColor;
out vec2 TexCoord;

uniform float xOffset;
uniform float yOffset;
uniform float scale;

void main()
{
	gl_Position = vec4(pos1.x + xOffset, pos1.y + yOffset, pos1.z, scale);
	TexCoord = aTexCoord;
	aColor = vertColor;
};