//
//  Event.h
//  Clue
//
//  Created by Jonathan Gillis on 2/12/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#ifndef __Clue__Event__
#define __Clue__Event__

#include <chrono>

namespace jdg {

	enum struct EventType
	{
		kInvalidEvent=0, 
		kMouseButtonEvent=1,
		kCursorPosEvent,
		kCursorEnterEvent,
		kScrollEvent,
		kKeyEvent,
		kUnicodeCharEvent,
		kFileDropEvent,
		kWindowEvent //Not used yet
	};

	struct Event
	{
		Event(EventType t,
			  std::chrono::time_point<std::chrono::system_clock> tm);

		EventType type;
		std::chrono::time_point<std::chrono::system_clock> timestamp;

		union EventParams {

			struct {
				int button;
				int action;
				int mods;
			} MouseButtonParams;

			struct {
				double xpos;
				double ypos;
			} CursorPosParams;

			struct {
				int entered;
			} CursorEnterParams;

			struct {
				int key;
				int scancode;
				int action;
				int mods;
			} KeyParams;
		} Params;
	};

}

#endif /* defined(__Clue__Event__) */
