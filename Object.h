//
//  Object.h
//  Clue
//
//  Created by Jonathan Gillis on 2/10/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#ifndef __Clue__Object__
#define __Clue__Object__
#include <OpenGL/gl3.h>

//do not include legacy gl.h
#define __gl_h_
#include <cstdint>
#include <cstdlib>
#include <GLFW/glfw3.h>
#include "Vector.h"
#include "Shader.h"

namespace jdg{
	namespace gui{

		class Object
		{
			typedef vector3<GLfloat> vec3;
			vec3 pts[4];
			GLuint vbo, vao;
			Shader vshader, fshader;

			void initialize_vao();
		public:
			void move(vec3 ds);
			Object();
		};
	}
}

#endif /* defined(__Clue__Object__) */
