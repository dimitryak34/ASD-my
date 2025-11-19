// forked from 2024 Marina Usova

#include <gtest/gtest.h>
#include "../lib_list/lin_list.h"

TEST(testList, test_default_constr) {
	List<int> l1;

	ASSERT_NO_THROW(l1.tail(), nullptr);
	ASSERT_NO_THROW(l1.head(), nullptr);
	ASSERT_NO_THROW(l1.count(), 0);

}


TEST(testList, test_non_empty_list) {
	List<int> l1;

	EXPECT_NO_THROW(l1.pushBack(1));
	EXPECT_EQ(l1.tail()->_obj, 1);

	EXPECT_NO_THROW(l1.pushBack(2));
	EXPECT_EQ(l1.tail()->_obj, 2);

	EXPECT_NO_THROW(l1.pushBack(3));
	EXPECT_EQ(l1.tail()->_obj, 3);
	EXPECT_EQ(l1.count(), 3);

	EXPECT_NO_THROW(l1.pushBack(4));
	EXPECT_NO_THROW(l1.pushBack(5));
	EXPECT_NO_THROW(l1.pushBack(6));
	EXPECT_NO_THROW(l1.pushBack(7));
	EXPECT_EQ(l1.count(), 7);

}
TEST(testList, test_push_front_func) {
	List<int> l1;

	EXPECT_EQ(l1.count(), 0);

	EXPECT_NO_THROW(l1.pushFront(1));
	EXPECT_EQ(l1.head()->_obj, 1);
	EXPECT_EQ(l1.count(), 1);

}


TEST(testList, test_pop_front_func) {
	List<int> l1;

	EXPECT_NO_THROW(l1.pushBack(4));
	EXPECT_NO_THROW(l1.pushBack(5));
	EXPECT_NO_THROW(l1.popFront());

	EXPECT_EQ(l1.head()->_obj, 5);
	EXPECT_EQ(l1.count(), 1);

}
TEST(testList, test_erase_func) {
	List<int> l1;

	EXPECT_NO_THROW(l1.pushBack(4));
	EXPECT_NO_THROW(l1.pushBack(5));
	EXPECT_NO_THROW(l1.pushBack(6));
	EXPECT_NO_THROW(l1.erase(2));
	EXPECT_EQ(l1.tail()->_obj, 5);
	EXPECT_EQ(l1.count(), 2);


}