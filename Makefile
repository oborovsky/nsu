CC ?= gcc
CXX = g++
CFLAGS = -g -Wall
LDFLAGS =
HOMEDIR = .
TARGET = reversestr test
TEST_CXXFLAGS = -g -Wall -L/opt/gtest/lib -lgtest -lgtest_main -lpthread
INCS = -I/opt/gtest/include

all: $(TARGET)

#test: $(OBJS)
#	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
test: fib.o fib_unittest.o
	$(CXX) $(TEST_CXXFLAGS) $(INCS) -o test_fib main_test.c $^

fib.o:fib.c
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@ $(INCS)

fib_unittest.o: fib_unittest.c
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@ $(INCS)	

reversestr: reversestr.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(HOMEDIR)/*.o $(TARGET)

.PHONY: all clean