CXX = g++
CXXFLAGS = -g -Wall
LDFLAGS = -lgtest -lgtest_main -lpthread #-L/opt/gtest/lib 
INCS = -I./ -I../ #-I/opt/gtest/include
SRC = ..
OBJ = $(SRC)/t1.o t1_unittest.o
TARGET = t1
all: $(TARGET)
	
t1: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ main_test.c $(OBJ) $(INCS) $(LDFLAGS)

.c.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)
clean:
	rm t1 $(SRC)/*.o *.o

.PHONY: all clean
