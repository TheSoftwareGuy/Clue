//
//  EventQueue.h
//  Clue
//
//  Created by Jonathan Gillis on 2/12/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#ifndef __Clue__EventQueue__
#define __Clue__EventQueue__

#include "Event.h"
#include <mutex>
#include <vector>
#include <memory>

namespace jdg {
	class EventQueue
	{
	public:
		std::timed_mutex mtx;
		void forwardEvent( Event* ev);
		bool empty();
		
	private:
		std::vector<Event*> queue;
	};
}

#endif /* defined(__Clue__EventQueue__) */
