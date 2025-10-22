#include <gtest/gtest.h>
#include "algorithms.h"

TEST(testBrackets, test_empty_string) {
	std::string s = "";

	EXPECT_EQ(checkBrackets(s), true);
}
TEST(testBrackets, test_twice_round_bracket) {
	std::string s = "()";

	EXPECT_EQ(checkBrackets(s), true);

}
TEST(testBrackets, test_twice_round_bracket_with_symbols) {
	std::string s = "adadg(sfbdfb)sfbsf";

	EXPECT_EQ(checkBrackets(s), true);

}
TEST(testBrackets, test_round_bracket) {
	std::string s = "(";

	EXPECT_EQ(checkBrackets(s), false);

}

TEST(testBrackets, test_figure_bracket) {
	std::string s = "{";

	EXPECT_EQ(checkBrackets(s), false);

}
TEST(testBrackets, test_brackets_hard_true_1) {
	std::string s = "((()))";

	EXPECT_EQ(checkBrackets(s), true);

}

TEST(testBrackets, test_brackets_hard_true_2) {
	std::string s = "([[{{}}]])";

	EXPECT_EQ(checkBrackets(s), true);

}

TEST(testBrackets, test_brackets_hard_false_1) {
	std::string s = "([[{{}}]]]";

	EXPECT_EQ(checkBrackets(s), false);

}
