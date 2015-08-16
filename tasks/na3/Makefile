CC ?= gcc
CXX = g++
CFLAGS = -g -Wall
LDFLAGS =
HOMEDIR = .
TARGET = t1
INCS = 
OBJ = t1.o

all: $(TARGET)

t1: t1.o
	$(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CXX) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CXX) $(CFLAGS) -c -o $@ $<

%.o: %.cc %.h
	$(CXX) $(CFLAGS) -c -o $@ $<

%.o: %.cc
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(HOMEDIR)/*.o $(TARGET) *.coding *.decoding

.PHONY: all clean