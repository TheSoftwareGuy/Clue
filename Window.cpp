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
using namespace clue;

Window::Window()
{
	win = glfwCreateWindow( 400, 400, "Window", NULL, NULL);
	make_current();
}

void Window::make_current()
{
	glfwMakeContextCurrent(win);
}

void Window::swap_buffers()
{
	glfwSwapBuffers(win);
}
