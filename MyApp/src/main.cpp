#include <application.hpp>

#include <GLFW\glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	auto mWindow = glfwCreateWindow(mWidth, mHeight, "Application", nullptr, nullptr);

	// Check for valid context
	if (nullptr == mWindow) {
		fprintf(stderr, "Failed to create OpenGL context");
		return EXIT_FAILURE;
	}

	// Create context and load OpenGL functions
	glfwMakeContextCurrent(mWindow);
	gladLoadGL();
	fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));

	// Rendering Loop
	while (false == glfwWindowShouldClose(mWindow)) {
		if (GLFW_PRESS == glfwGetKey(mWindow, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(mWindow, true);
		}

		// Background fill color
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Flip buffers and draw
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

	glfwTerminate();

    return EXIT_SUCCESS;
}
