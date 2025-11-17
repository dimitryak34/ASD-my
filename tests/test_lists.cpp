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
	EXPECT_NO_THROW(l1.pushBack(2));
	EXPECT_NO_THROW(l1.pushBack(3));
	EXPECT_NO_THROW(l1.pushBack(4));
	EXPECT_NO_THROW(l1.pushBack(5));
	EXPECT_NO_THROW(l1.pushBack(6));
	EXPECT_NO_THROW(l1.pushBack(7));



}