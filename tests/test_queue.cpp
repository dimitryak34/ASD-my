#include "queue.h"
#include <gtest/gtest.h>

TEST(testQueue, can_init_queue) {
	ASSERT_NO_THROW(TQueue({1, 2, 3, 4}));
}

TEST(testQueue, test_default_constr) {
	TQueue<int> q1;

	EXPECT_EQ(q1.size(), 0);
	EXPECT_EQ(q1.count(), 0);
	EXPECT_EQ(q1.head(), -1);

}