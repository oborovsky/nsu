//#include "test_reversestr.h"
#include <string.h>
#include "cu/cu.h"
#include "../reversestr.h"

TEST(emptyString)
{
	assertEquals(e2s(""),"");
}

TEST(oneLetter)
{
	char* c = "E";
	assertTrue(strcmp(e2s(c),c));
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