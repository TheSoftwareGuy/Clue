//
//  Event.cpp
//  Clue
//
//  Created by Jonathan Gillis on 2/12/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#include "Event.h"

jdg::Event( jdg::EventType t, std::chrono::time_point<system_clock> tm)
{
	time = tm;
}
