//
//  Object.cpp
//  Clue
//
//  Created by Jonathan Gillis on 2/10/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#include "Object.h"
#include <GLFW/glfw3.h>

using namespace jdg;
using namespace gui;


Object::Object()
{
	pts[0] = { 0.0, 0.0, 0.0};
	pts[1] = { 0.0, 0.0, 0.0};
	pts[2] = { 5.0, 0.0, 0.0};
	pts[3] = { 5.0, 5.0, 0.0};

	initialize_vao();

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pts), pts, GL_STATIC_DRAW);


}

void Object::initialize_vao()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}