CC ?= gcc
CFLAGS = -g -Wall -pedantic --std=gnu99
LDFLAGS = -Lcu/ -lcu

OBJS = test_reversestr.o test.o

all: test

test: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o test

.PHONY: all clean