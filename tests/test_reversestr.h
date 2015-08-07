#ifndef _TEST_REVERSESTR_H_
#define _TEST_REVERSESTR_H_

#include "cu/cu.h"

TEST(oneLetter);
TEST(word);
TEST(emptyString);
TEST(phrase);

TEST_SUITE(testReverseString)
{
	TEST_ADD(emptyString),
	TEST_ADD(oneLetter),
	TEST_ADD(word),
	TEST_ADD(phrase),
	TEST_SUITE_CLOSURE
};
#endif //_TEST_REVERSESTR_H_