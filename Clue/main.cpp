//
//  main.cpp
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//


//Just trying to test the configuratuions
#include <GLFW/glfw3.h>
#include <iostream>
#include <cassert>

class Window
{
public:
	GLFWwindow* win;
	Window(int width=400, int height=400)
	{
		win = glfwCreateWindow( width, height, "Window 1", NULL, NULL);
		assert(win != NULL);
	}


	void makeCurrent(){
		glfwMakeContextCurrent(win);
	}

	void swapBuffers(){
		glfwSwapBuffers(win);
	}
};

void close_window(GLFWwindow * win)
{

}

int main()
{
	if ( !glfwInit()) {
		std::cerr << "Failed to initialize GLFW! I'm out!" << std::endl;
		exit(-1);
	}

	// Open a window and attach an OpenGL rendering context to the window surface
	Window win;
	win.makeCurrent();
	// Use red to clear the screen
	glClearColor(1, 0, 0, 1);

	// Create a rendering loop
	int running = GL_TRUE;
	while(!glfwWindowShouldClose(win.win)) {
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers
		win.swapBuffers();
	}

	// Terminate GLFW
	glfwTerminate();

	return 0;
}

