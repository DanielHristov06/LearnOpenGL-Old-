#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	//Initialize GLFW
	glfwInit();

	//Tell GLFW which version of OpenGL we are using (3.3)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Tell GLFW we are using the core profile (we only have the modern functions)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create a window object
	GLFWwindow* window = glfwCreateWindow(1600, 900, "Ne haresvam Ivan", NULL, NULL);

	//Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create a window." << std::endl;
		glfwTerminate();
		return -1;
	}

	//Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD
	gladLoadGL();

	//Specify the viewport of OpenGL in the window
	glViewport(0, 0, 1600, 900);

	//Specify the color of the background
	glClearColor(51.0f / 255.0f, 153.0f / 255.0f, 1.0f, 1.0f);
	//Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	//Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	//Main while loop
	while (!glfwWindowShouldClose(window)) {
		//Take care of all GLFW events
		glfwPollEvents();
	}

	//Delete window
	glfwDestroyWindow(window);
	//Terminate GLFW
	glfwTerminate();
	return 0;
}