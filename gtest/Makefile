CXX = g++
CXXFLAGS = -g -Wall
LDFLAGS = -lgtest -lgtest_main -lpthread #-L/opt/gtest/lib 
INCS = -I./ -I../ #-I/opt/gtest/include
SRC = ..
OBJ = ../fib.o fib_unittest.o
TARGET = test
all: $(TARGET)
	
test: $(OBJ)
	$(CXX) $(CXXFLAGS) -o test main_test.c $(OBJ) $(INCS) $(LDFLAGS)

.c.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm test $(SRC)/*.o *.o

.PHONY: all clean
