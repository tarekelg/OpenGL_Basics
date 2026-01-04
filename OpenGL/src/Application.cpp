//GLEW 
#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>
#include <iostream>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	//When user presses the escape key, we set the WindowShouldClose property to true

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() {
	
	//create Window hint -> entails metadata for the window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// signals glfw that we want to use opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //application will throw an error when using legacy functions
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//create the window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);

	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//register function with the proper glfw callback function
	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);

	//initialize glew
	glewExperimental = GL_TRUE; // Setting glewExperimental to true ensures GLEW uses more modern techniques for managing OpenGL functionality

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	//creating a viewport
	glViewport(0, 0, 800, 600);


	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();//checks if any event is triggered like key input etc.

		//Rendering colors
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window); //double buffer 
	}

	glfwTerminate();
	
	return 0;
		}


