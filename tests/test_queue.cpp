#include "queue.h"
#include <gtest/gtest.h>
#define TRASH -2453563568

TEST(testQueue, can_init_queue) {
	TQueue q1({ 1, 2, 3, 4 });

	ASSERT_NO_THROW(TQueue({1, 2, 3, 4}));
	EXPECT_EQ(q1.elem(0), 1);
	EXPECT_EQ(q1.elem(1), 2);
	EXPECT_EQ(q1.elem(2), 3);
	EXPECT_EQ(q1.elem(3), 4);

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

TEST(testQueue, test_push_func_1) {
	TQueue<long> q1({ TRASH, TRASH, 2, 3, 4, 5, TRASH, TRASH });
	q1.setIndHead(5);
	q1.setCount(4);

	EXPECT_EQ(q1.size(), 8);
	EXPECT_NO_THROW(q1.push(1));
	EXPECT_EQ(q1.elem(1), 1);		
	EXPECT_EQ(q1.indHead(), 5);
	EXPECT_EQ(q1.count(), 5);

	EXPECT_NO_THROW(q1.push(0));
	EXPECT_EQ(q1.elem(0), 0);
	EXPECT_EQ(q1.count(), 6);

	EXPECT_NO_THROW(q1.push(7));
	EXPECT_EQ(q1.elem(7), 7);
	EXPECT_EQ(q1.count(), 7);

	EXPECT_NO_THROW(q1.push(6));
	EXPECT_EQ(q1.elem(6), 6);
	EXPECT_EQ(q1.count(), 8);

	EXPECT_ANY_THROW(q1.push(6));

}
TEST(testQueue, test_push_func_2) {
	TQueue<long> q1({ 0, TRASH, TRASH , TRASH , TRASH });
	q1.setCount(1);
	q1.setIndHead(0);

	EXPECT_NO_THROW(q1.push(4));
	EXPECT_EQ(q1.elem(4), 4);
	EXPECT_EQ(q1.count(), 2);

	EXPECT_NO_THROW(q1.push(3));
	EXPECT_EQ(q1.elem(3), 3);
	EXPECT_EQ(q1.count(), 3);

	EXPECT_NO_THROW(q1.push(2));
	EXPECT_EQ(q1.elem(2), 2);
	EXPECT_EQ(q1.count(), 4);

}

TEST(testQueue, test_pop_func_1) {
	TQueue<long> q1({ TRASH, TRASH, 2, 3, 4, 5, TRASH, TRASH });
	q1.setIndHead(5);
	q1.setCount(4);

	EXPECT_NO_THROW(q1.pop());
	EXPECT_EQ(q1.head(), 4);
	EXPECT_EQ(q1.count(), 3);

}
TEST(testQueue, test_pop_func_2) {
	TQueue<long> q1({ 0, 1, TRASH, TRASH, 4, 5, 6, 7 });
	q1.setCount(6);
	q1.setIndHead(1);

	EXPECT_NO_THROW(q1.pop());
	EXPECT_EQ(q1.head(), 0);
	EXPECT_EQ(q1.count(), 5);

	EXPECT_NO_THROW(q1.pop());
	EXPECT_EQ(q1.head(), 7);
	EXPECT_EQ(q1.count(), 4);

}
TEST(testQueue, test_pop_func_3) {
	TQueue<long> q1({ 0, TRASH, TRASH , TRASH , TRASH });
	q1.setCount(1);
	q1.setIndHead(0);
	
	EXPECT_NO_THROW(q1.pop());
	//EXPECT_EQ(q1.head(), 4);
	EXPECT_EQ(q1.indHead(), 0);
	EXPECT_EQ(q1.count(), 0);

	EXPECT_ANY_THROW(q1.pop());


}