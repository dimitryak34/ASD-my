#include "queue.h"
#include <gtest/gtest.h>

TEST(testQueue, can_init_queue) {
	ASSERT_NO_THROW(TQueue({1, 2, 3, 4}));
}

