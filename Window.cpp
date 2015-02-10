//
//  Window.cpp
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#include "Window.h"
#include <gtest/gtest.h>

jdg::clue::Window::Window(int width, int height, std::string name )
{
		win = glfwCreateWindow( width, height, name.c_str(), NULL, NULL);
}

void jdg::clue::Window::make_current()
{
	glfwMakeContextCurrent(win);
}

void jdg::clue::Window::swap_buffers()
{
	glfwSwapBuffers(win);
}
