//#include "test_reversestr.h"
#include <string.h>
#include "cu/cu.h"
#include "../reversestr.h"

TEST(emptyString)
{	char *str= "a";
	e2s(str);
	assertEquals(1,1);
}

TEST(oneLetter)
{
	char* c = "E";
	assertEquals(c,c);
}
/*
TEST(word)
{
	assertEquals(e2s("word"),"drow");
}

TEST(phrase)
{
	assertEquals(e2s("one phrase"),"esarhp eno");
}
*/