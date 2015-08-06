#include "cu/cu.h"
#include <stdio.h>
#include "../reversestr.h"

TEST(oneLetter)
{
	assertEquals(e2s('a'),'a');
}
TEST(word)
{
	assertEquals(e2s("word"),"drow");
}
TEST(emptyString)
{
	assertEquals(e2s(""),"");
}
TEST(phrase)
{
	assertEquals(e2s("it's a whole phrase"), "esarhp elohw a s'ti");
}