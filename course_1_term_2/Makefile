CC ?= gcc
CXX = g++
CFLAGS = -g -Wall
LDFLAGS =
HOMEDIR = .
TARGET = qsort
INCS = 

all: $(TARGET)

reversestr: reversestr.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(HOMEDIR)/*.o $(TARGET)

.PHONY: all clean