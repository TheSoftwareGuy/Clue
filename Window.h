//
//  Window.h
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#ifndef __Clue__Window__
#define __Clue__Window__

#include <string>
#include "Vector.h"
#include <GLFW/glfw3.h>



namespace jdg {
	namespace clue{
			class Window
			{
			private:

				GLFWwindow *win;
			public:
				struct Cursor
				{
				private:
					friend class Window;
					vector3<double> pos;
					Window *parent;
				public:
					vector3<double> getOffset();
					void moveTo(vector3<double> pt);
					void lineTo(vector3<double> pt);
				};

				Window();
				void make_current();
				void swap_buffers();
				
			};
	} //namespace clue
}//namespace jdg
#endif /* defined(__Clue__Window__) */
