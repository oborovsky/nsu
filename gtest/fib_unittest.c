#include "gtest/gtest.h"

int fib(int n);

TEST(fibbonachiTest, Zero) {
	EXPECT_EQ(0, fib(0));
}
TEST(fibbonachiTest, Pozitive) {
	EXPECT_EQ(1, fib(1));
	EXPECT_EQ(2, fib(2));
	EXPECT_EQ(3, fib(3));
	EXPECT_EQ(5, fib(4));
}