//
//  EventQueue.cpp
//  Clue
//
//  Created by Jonathan Gillis on 2/12/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#include "EventQueue.h"

using namespace jdg;
using namespace std::chrono;

bool EventQueue::postEvent(Event& ev)
{
	//lock the object
	std::lock_guard<std::timed_mutex> lock(mtx);

	if(registered.find(ev.type) != registered.end()){
		queue.push_back(&ev);
		return true;
	}
	return false;
}

Event* EventQueue::pollEvent(EventType t)
{
	Event* result = nullptr;
	if (!queue.empty()){
		std::lock_guard<std::timed_mutex> lock(mtx);

		if (t == EventType::kAnyEvent) {
			result = queue.front();
			queue.erase(queue.begin());
			return result;
		}
		for(std::vector<Event*>::const_iterator iter = queue.cbegin();
			iter != queue.cend();
			++iter)
		{
			if ((*iter)->type == t) {
				result = *iter;
				queue.erase(iter);
			}
		}
	}
	return nullptr;
}

void EventQueue::register_event(EventType t)
{
	std::lock_guard<std::timed_mutex> lock(mtx);
	registered.insert(t);
}
