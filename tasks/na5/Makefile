.PHONY: all clean
CC = g++
CPPFLAGS = -g -Wall -std=c++11
#CPPFLAGS += -isystem $(GTEST_DIR)/include
FLAGS = -Wall -g -Wextra -pthread
GTEST_DIR = /usr/local
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all: na5t1

clean:
	rm -f *.o na5t1

fib: fib.o fib_unittest.o
	$(CC) $(CPPFLAGS) $(FLAGS) -pthread $^ -lgtest_main -lgtest -o $@

fib.o: fib.cc fib.h $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) -c $(FLAGS) $<

fib_unittest.o: fib_unittest.cc fib.h $(GTEST_HEADERS)
	$(CC) -c $(CPPFLAGS) $(FLAGS) $<

na5t1: na5t1.o
	g++ $(CPPFLAGS) $^ -o $@

.cc.o :
	$(CC) -c $(CPPFLAGS) $<
