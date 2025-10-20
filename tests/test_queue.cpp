#include "queue.h"
#include <gtest/gtest.h>

TEST(testQueue, can_init_queue) {
	ASSERT_NO_THROW(TQueue({1, 2, 3, 4}));
}

TEST(testQueue, test_default_constr) {
	TQueue<int> q1;

	EXPECT_EQ(q1.size(), 0);
	EXPECT_EQ(q1.count(), 0);
	EXPECT_EQ(q1.indHead(), -1);

}
TEST(testQueue, test_init_constr) {
	TQueue<int> q1(10);

	EXPECT_EQ(q1.count(), 0);
	EXPECT_EQ(q1.size(), 10);

}


TEST(testQueue, test_head_func) {
	TQueue<int> q1({ 2, 4, 8, NULL, NULL, 2 });

	EXPECT_EQ(q1.size(), 6);
	EXPECT_EQ(q1.head(), 2);


}

TEST(testQueue, test_push_func) {
	TQueue<int> q1({ -1, -1, 2, 3, 4, 5, -1, -1 });
	q1.setIndHead(5);
	q1.setCount(4);

	EXPECT_EQ(q1.size(), 8);
	EXPECT_NO_THROW(q1.push(1));
	EXPECT_EQ(q1.elem(1), 1);		// elem(0) == 1 why????????????????
	EXPECT_EQ(q1.indHead(), 5);
	EXPECT_EQ(q1.count(), 5);



}