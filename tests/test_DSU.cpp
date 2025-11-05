// forked from 2024 Marina Usova
#include <gtest/gtest.h>
#include "../lib_DSU/DSU.h"

TEST(testDSU, test_1_find_func) {
	DSU t1(6);
	EXPECT_EQ(t1.find(0), 0);
	EXPECT_EQ(t1.find(1), 1);
	EXPECT_EQ(t1.find(2), 2);
	EXPECT_EQ(t1.find(3), 3);
	EXPECT_EQ(t1.find(4), 4);
	EXPECT_EQ(t1.find(5), 5);

}

TEST(testDSU, test_1_unite) {
	DSU t1(6);
	ASSERT_NO_THROW(t1.unite(0, 1));
	ASSERT_NO_THROW(t1.unite(0, 2));
	ASSERT_NO_THROW(t1.unite(0, 3));
	ASSERT_NO_THROW(t1.unite(0, 4));

	ASSERT_NO_THROW(t1.unite(3, 5));
	EXPECT_EQ(t1.find(5), 0);

}

TEST(testDSU, test_2_unite) {
	DSU t(7);
	ASSERT_NO_THROW(t.unite(3, 6));
}