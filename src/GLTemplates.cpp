#include "GLTemplates.h"


unsigned int EBO;
unsigned int VBO[VBO_SIZE] = {0};
unsigned int VAO[VAO_SIZE] = {0};
unsigned int texture;

const unsigned int indices[] = {
	0, 1, 3,  // first triangle
	1, 2, 3   // second triangle
};


const float VtriangleP[9] = {
   -0.5f, -0.5f, 0.0f,  // bottom right
	0.5f, -0.5f, 0.0f,  // bottom left
	0.0f,  0.5f, 0.0f   // top
};

const float VrectangleP[12] = {
	0.5f,  0.5f, 0.0f,  // top right
	0.5f, -0.5f, 0.0f,  // bottom right
   -0.5f, -0.5f, 0.0f,  // bottom left
   -0.5f,  0.5f, 0.0f   // top left 
};




const float VtrianglePC[18] = {
	// positions        // colors
	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
};

const float VrectanglePC[24] = {
	// positions         // colors
	0.5f,  0.5f, 0.0f,	 1.0f, 0.0f, 0.0f,  // top right
	0.5f, -0.5f, 0.0f,	 0.0f, 1.0f, 0.0f,  // bottom right
   -0.5f, -0.5f, 0.0f,	 0.0f, 0.0f, 1.0f,  // bottom left
   -0.5f,  0.5f, 0.0f,	 1.0f, 1.0f, 1.0f   // top left 
};




const float VtrianglePT[15] = {
	// positions         // texture coords
   -0.5f, -0.5f, 0.0f,	 0.0f, 0.0f,   // top right
	0.5f, -0.5f, 0.0f,	 0.0f, 0.0f,   // bottom right
	0.0f,  0.5f, 0.0f,	 0.0f, 0.0f,   // bottom left
};

const float VrectanglePT[20] = {
	// positions         // texture coords
	0.5f,  0.5f, 0.0f,	 1.0f, 1.0f,   // top right
	0.5f, -0.5f, 0.0f,	 1.0f, 0.0f,   // bottom right
   -0.5f, -0.5f, 0.0f,	 0.0f, 0.0f,   // bottom left
   -0.5f,  0.5f, 0.0f,	 0.0f, 1.0f    // top left 
};




const float VtrianglePCT[24] = {
	// positions         // colors           // texture coords
   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,   // top right
	0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,   // bottom right
    0.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,   // bottom left
};

const float VrectanglePCT[32] = {
	// positions         // colors           // texture coords
	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};


void createTriangleC(Shader& shader, const char* name, float R, float G, float B)
{
	shader.use();
	glBindVertexArray(VAO[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glUniform4f(glGetUniformLocation(shader.ID, name), R, G, B, 1.0f);
}

void createRectangleC(Shader& shader, const char* name, float R, float G, float B)
{
	shader.use();
	glBindVertexArray(VAO[1]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glUniform4f(glGetUniformLocation(shader.ID, name), R, G, B, 1.0f);
}


void createTriangleVC(Shader& shader) {
	shader.use();
	glBindVertexArray(VAO[2]);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void createRectangleVC(Shader& shader) {
	shader.use();
	glBindVertexArray(VAO[3]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void createTriangleT(Shader& shader, int textureID) {
	shader.use();
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBindVertexArray(VAO[4]);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void createRectangleT(Shader& shader, int textureID) {
	shader.use();
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBindVertexArray(VAO[5]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void createTriangleTVC(Shader& shader, int textureID) {
	shader.use();
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBindVertexArray(VAO[6]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

}
void createRectangleTVC(Shader& shader, int textureID) {
	shader.use();
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBindVertexArray(VAO[7]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
