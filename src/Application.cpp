//#include <iostream>
//#include <thread>
//#include <chrono>

#include "shaders.h"
#include "GLTemplates.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

bool debugMode = false;
bool mipmapMode = false;
char inputDelayTime = 0;

float xOffset = 0.f;
float yOffset = 0.f;

float xSpeed = 0.f;
float ySpeed = 0.f;

const float Gravity = -0.005f;


int main()
{
	glfwInit();
	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(1320, 790, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "failed to create window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // V-SYNC

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "failed to initialize GLAD\n";
		return -1;
	}

	Shader shader1 = Shader("src/shaders/vertex_shader1.glsl", "src/shaders/fragment_shader1.glsl");
	Shader shader2 = Shader("src/shaders/vertex_shader2.glsl", "src/shaders/fragment_shader2.glsl");
	Shader shader3 = Shader("src/shaders/vertex_shader3.glsl", "src/shaders/fragment_shader3.glsl");
	Shader shader4 = Shader("src/shaders/vertex_shader4.glsl", "src/shaders/fragment_shader4.glsl");



	glGenVertexArrays(sizeof(VAO) / sizeof(VAO[0]), VAO); // cria os VAOs
	glGenBuffers(sizeof(VBO) / sizeof(VBO[0]), VBO); // cria os VBOs
	glGenBuffers(1, &EBO); // cria o EBO

	glGenTextures(1, &texture); // create texture ID


/*--------------------------------------------------------------------------------------------------------------------*/
	glBindVertexArray(VAO[0]); // vinculamos o VAO[0]
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]); // vinculamos o VBO[0] ao VAO[0]
	glBufferData(GL_ARRAY_BUFFER, sizeof(VtriangleP), VtriangleP, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	glBindVertexArray(VAO[1]); // vinculamos o VAO[1]
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]); // vinculamos o VBO[1] ao VAO[1]
	glBufferData(GL_ARRAY_BUFFER, sizeof(VrectangleP), VrectangleP, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // vinculamos o EBO ao VAO[1]
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
	glBindVertexArray(VAO[2]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VtrianglePC), VtrianglePC, GL_STREAM_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	glBindVertexArray(VAO[3]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VrectanglePC), VrectanglePC, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
/*--------------------------------------------------------------------------------------------------------------------*/
	

/*--------------------------------------------------------------------------------------------------------------------*/
	glBindVertexArray(VAO[4]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[4]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VtrianglePT), VtrianglePT, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);


	glBindVertexArray(VAO[5]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[5]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VrectanglePT), VrectanglePT, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);
/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
	glBindVertexArray(VAO[6]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[6]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VtrianglePCT), VtrianglePCT, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);/////////////////////////////////
	glEnableVertexAttribArray(0);

	// color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));///////////////
	glEnableVertexAttribArray(1);

	// texture
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));///////////////
	glEnableVertexAttribArray(2);


	glBindVertexArray(VAO[7]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[7]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VrectanglePCT), VrectanglePCT, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
/*--------------------------------------------------------------------------------------------------------------------*/


	Texture texture1 = Texture("assets/container.jpg");
	texture1.free();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	xOffset = 0.f;
	float scale = 2.f;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//inputs
		processInput(window);


		shader3.setFloat("scale", scale);
		shader3.setFloat("yOffset", yOffset);
		shader3.setFloat("xOffset", xOffset);


		createRectangleT(shader3, texture);


		if (yOffset > -1.5f)
			ySpeed += Gravity;

		else if (yOffset < -scale + 0.5f)
		{
			ySpeed = 0.f;
			yOffset = -scale + 0.5f;
		}
		// apply the gravity
		yOffset += ySpeed;


		if (inputDelayTime < 15)
			inputDelayTime += 1;

		else if (inputDelayTime > 15)
			inputDelayTime = 0;


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteProgram(shader1.ID);
	glDeleteProgram(shader2.ID);
	glDeleteProgram(shader3.ID);
	glDeleteProgram(shader4.ID);

	glfwTerminate();
}



void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS && inputDelayTime == 15)
	{
		debugMode = !debugMode;

		if (debugMode)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		inputDelayTime = 0;
	}
	if (glfwGetKey(window, GLFW_KEY_F2) == GLFW_PRESS && inputDelayTime == 15)
	{
		mipmapMode = !mipmapMode;
		glBindTexture(GL_TEXTURE_2D, texture);

		if (mipmapMode)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		}
		else
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		inputDelayTime = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && inputDelayTime == 15)
	{
		ySpeed = 0.15f;

		inputDelayTime = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		xOffset -= 0.05f;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		xOffset += 0.05f;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}