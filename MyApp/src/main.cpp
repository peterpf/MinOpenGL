#include <application.hpp>

// Standard Headers
#include <stdlib.h>
#include <stdio.h>

void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

static void framebuffersize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main(int argc, char *argv[]) {
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(mWidth, mHeight, "Application", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffersize_callback);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);
	fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));

	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

	// Rendering Loop
	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		int w, h;
		glfwGetFramebufferSize(window, &w, &h);
		glColor3f(1.0, 1.0, 1.0);

		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.75, 0.75);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.75, -0.75);
		glVertex2f(-0.75, -0.75);
		glEnd();

		// Flip buffers and draw
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	exit(EXIT_SUCCESS);
}
