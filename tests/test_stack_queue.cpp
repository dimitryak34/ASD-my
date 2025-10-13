#include <gtest/gtest.h>
#include "stack.h"

TEST(testStack, test_constr_default) {
	Stack<char> s1;

	EXPECT_EQ(s1.size(), 0);
	EXPECT_EQ(s1.topIndex(), -1);

}
TEST(testStack, test_constr_init_1) {
	int len = 5;
	int* mas = new int[len];
	for (int i = 0; i < len; i++) {
		mas[i] = i;
	}

	Stack<int> s(mas, len);

	ASSERT_EQ(s.topIndex(), 4);
	EXPECT_EQ(s.size(), len);

}
TEST(testStack, test_constr_init_2) {
	int len = 5;

	Stack<int> s({ 0, 1, 2, 3, 4 });

	ASSERT_EQ(s.topIndex(), 4);
	EXPECT_EQ(s.size(), len);

}
TEST(testStack, test_constr_init_3) {
	int len = 10;
	Stack<int> s(len);

	EXPECT_EQ(s.size(), len);
	EXPECT_EQ(s.topIndex(), -1);
}

TEST(testStack, test_top_method) {
	int len = 3;
	Stack<int> s({ 1, 2, 3 });

	ASSERT_EQ(s.top(), 3);
}

TEST(testStack, test_can_push_elem) {
	int len = 3;
	

	Stack<int> s( len);

	EXPECT_NO_THROW(s.push(10));
	EXPECT_NO_THROW(s.push(10));
	EXPECT_NO_THROW(s.push(10));
	EXPECT_ANY_THROW(s.push(10));
}
TEST(testStack, test_can_pop_elem) {
	int len = 3;
	Stack<int> s({ 1, 2, 3 });

	EXPECT_NO_THROW(s.pop());
	EXPECT_NO_THROW(s.pop());
	EXPECT_NO_THROW(s.pop());
	EXPECT_ANY_THROW(s.pop());

}
