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
#include <GLFW/glfw3.h>


namespace jdg {
	namespace clue{
		namespace view{

			//forward declarations

			class Window
			{
			private:

				GLFWwindow *win;
			public:
				Window();
				void make_current();
				void swap_buffers();				
			};
		}
	} //namespace clue
}//namespace jdg
#endif /* defined(__Clue__Window__) */
