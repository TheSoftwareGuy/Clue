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


void keyboard_callback(GLFWwindow *win, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_Q && action == GLFW_PRESS){
		glfwTerminate();
		exit(0);
	}
}

class Window
{
public:
	GLFWwindow* win;
	Window(int width=400, int height=400)
	{
		win = glfwCreateWindow( width, height, "Window 1", NULL, NULL);
		assert(win != NULL);
		glfwSetKeyCallback(win, keyboard_callback);
	}


	void makeCurrent(){
		glfwMakeContextCurrent(win);
	}

	void swapBuffers(){
		glfwSwapBuffers(win);
	}
};


class Object
{
	GLfloat vertices_position[6] = {
		0.0, 0.0,
		0.5, 0.0,
		0.5, 0.5
	};
	GLuint vbo;
	GLuint vao;

	Object()
	{
		//generate the buffer
		glGenBuffers(1, &vbo);
		//allocate the space for the buffer (i think)
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//upload the buffer data
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_position), vertices_position, GL_STATIC_DRAW);

	}
};

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
	while(!glfwWindowShouldClose(win.win)) {
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers
		win.swapBuffers();
		glfwPollEvents();
	}

	// Terminate GLFW
	glfwTerminate();

	return 0;
}

