CXX = g++
CXXFLAGS = -g -Wall
LDFLAGS = -lgtest -lgtest_main -lpthread #-L/opt/gtest/lib 
INCS = -I./ -I../ #-I/opt/gtest/include
SRC = ..
OBJ = $(SRC)/na5t1.o na5t1_unittest.o
TARGET = test1
all: $(TARGET)
	
test1: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ main_test.c $(OBJ) $(INCS) $(LDFLAGS)

.c.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)
clean:
	rm test1 $(SRC)/*.o *.o

.PHONY: all clean
