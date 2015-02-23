//
//  main.cpp
//  EventQueueTests
//
//  Created by Jonathan Gillis on 2/12/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#include <gtest/gtest.h>

#include "EventQueue.h"

using namespace jdg;
class EventQueueTest : public testing::Test
{
protected:
};

TEST_F(EventQueueTest, GeneralTest )
{
	EventQueue q;
	Event ev(EventType::kMouseButtonEvent);
	Event* polled;
	ev.params.MouseButtonParams.button = 0;
	ev.params.MouseButtonParams.action = 0;
	ev.params.MouseButtonParams.mods   = 0;

	q.postEvent(ev);

	EXPECT_TRUE(q.empty());
	q.register_event(EventType::kMouseButtonEvent);
	q.postEvent(ev);
	EXPECT_FALSE(q.empty());
	polled = q.pollEvent(EventType::kAnyEvent);

	EXPECT_EQ(EventType::kMouseButtonEvent, polled->type);
}

int main(int argc, char * argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
