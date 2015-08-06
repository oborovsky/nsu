#include "cu/cu.h"

TEST(oneLetter);
TEST(word);
TEST(emptyString);
TEST(phrase);

TEST_SUITE(testReverseString) {
	TEST_ADD(oneLetter),
	TEST_ADD(word),
	TEST_ADD(emptyString),
	TEST_ADD(phrase),
	TEST_SUITE_CLOSURE
}
