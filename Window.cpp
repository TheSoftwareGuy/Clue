//
//  Window.cpp
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#include "Window.h"
#include <gtest/gtest.h>

using namespace jdg;
using namespace gui;

Window::Window(int width, int height, std::string name )
{
		win = glfwCreateWindow( width, height, name.c_str(), NULL, NULL);
}

void Window::make_current()
{
	glfwMakeContextCurrent(win);
}

void Window::swap_buffers()
{
	glfwSwapBuffers(win);
}
