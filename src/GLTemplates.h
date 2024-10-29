#pragma once

#include "../includes/glad/glad.h"
#include <GLFW/glfw3.h>

#include "shaders.h"

#include <iostream>

#define VAO_SIZE 8
#define VBO_SIZE 8

extern unsigned int EBO;
extern unsigned int texture;
// 0 = triangle
// 1 = rectangle
// 2 = triangleC  (vertex colored)
// 3 = rectangleC (vertex colored)
// 4 = triangle with texture
extern unsigned int VAO[VAO_SIZE];
extern unsigned int VBO[VBO_SIZE];

extern const unsigned int indices[6];

// basic shapes
extern const float VtriangleP[9];
extern const float VrectangleP[12];

// colored shapes
extern const float VtrianglePC[18];
extern const float VrectanglePC[24];

// textured shapes
extern const float VtrianglePT[15];
extern const float VrectanglePT[20];

extern const float VtrianglePCT[24];
extern const float VrectanglePCT[32];



void createTriangleC(Shader& shader, const char* name, float r, float g, float b);
void createRectangleC(Shader& shader, const char* name, float r, float g, float b);

void createTriangleVC(Shader& sahder);
void createRectangleVC(Shader& shader);

void createTriangleT(Shader& shader, int textureID);
void createRectangleT(Shader& shader, int textureID);

void createTriangleTVC(Shader& shader, int textureID);
void createRectangleTVC(Shader& shader, int textureID);