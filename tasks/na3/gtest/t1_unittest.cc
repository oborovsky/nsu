#include "gtest/gtest.h"

char code ( char ch, int step);
char decode(char ch, int step);
int findIndex(char ch, const char *abc);
char* catString(const char *str1, const char *str2);

TEST(codeTest, positiveStep)
{
	EXPECT_EQ('b', code('a',1));
	EXPECT_EQ('c', code('a',2));
	EXPECT_EQ('0', code('z',1));
	EXPECT_EQ('4', code('1',3));
}

TEST(codeTest, negativeStep)
{
	EXPECT_EQ('9', code('a', -1));
	EXPECT_EQ('z', code('0', -1));
	EXPECT_EQ('y', code('z', -1));
}

TEST(findIndexTest, steps123etc)
{
	const char *abc = "0123456789abcdefghijklmnopqrstuvwxyz";
	EXPECT_EQ(1, findIndex('1',abc) );
	EXPECT_EQ(0, findIndex('0', abc) );
	EXPECT_EQ(10, findIndex('a', abc) );
	EXPECT_EQ(35, findIndex('z', abc) );
	EXPECT_EQ(20, findIndex('k', abc) );
}

TEST(catStringTest, catTwoString)
{
	EXPECT_STREQ("one.two", catString("one", "two"));
	EXPECT_STREQ("one.", catString("one",""));
	EXPECT_STREQ(".two", catString("", "two"));
	EXPECT_STREQ(".", catString("", ""));
}

TEST(decodeTest, positiveStep)
{
	EXPECT_EQ('a', decode('b', 1));
	EXPECT_EQ('z', decode('0', 1));
	EXPECT_EQ('9', decode('a', 1));
	EXPECT_EQ('0', decode('9', 9));
	EXPECT_EQ('z', decode('0', 1));
}
TEST(decodeTest, negativeStep)
{
	EXPECT_EQ('b', decode('a', -1));
	EXPECT_EQ('0', decode('z', -1));
	EXPECT_EQ('1', decode('0', -1));
}
TEST(decodeCodeTest, positiveStep)
{
	EXPECT_EQ('a', decode( code('a',1), 1) );
	EXPECT_EQ('z', decode( code('z',1), 1) );
	EXPECT_EQ('0', decode( code('0', 1), 1) );
}
TEST(decodeCodeTest, negativeStep)
{
	EXPECT_EQ('a', decode( code('a',-1), -1) );
	EXPECT_EQ('z', decode( code('z',-1), -1) );
	EXPECT_EQ('0', decode( code('0', -1), -1) );	
}
TEST(codeDecodeTest, positiveStep)
{
	EXPECT_EQ('a', code( decode('a',1), 1) );
	EXPECT_EQ('z', code( decode('z',1), 1) );
	EXPECT_EQ('0', code( decode('0', 1), 1) );
}
TEST(codeDecodeTest, negativeStep)
{
	EXPECT_EQ('a', code( decode('a',-1), -1) );
	EXPECT_EQ('z', code( decode('z',-1), -1) );
	EXPECT_EQ('0', code( decode('0', -1), -1) );	
}
