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

void jdg::EventQueue::forwardEvent(Event* ev)
{
	std::lock_guard<std::timed_mutex> lock(mtx);
	queue.push_back(ev);
}

bool jdg::EventQueue::empty()
{
	return queue.empty();
}