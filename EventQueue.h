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
#include <set>

namespace jdg {
	class EventQueue
	{
		friend class EventQueueTest;
	public:
		std::timed_mutex mtx;
		bool postEvent(Event& ev);
		Event* pollEvent( EventType t=EventType::kAnyEvent);
		void register_event(EventType t);
		bool empty() {
			return queue.empty();
		}
	private:
		std::vector<Event*> queue;
		std::set<EventType> registered;
	};
}

#endif /* defined(__Clue__EventQueue__) */
