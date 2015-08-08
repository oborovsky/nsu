CC ?= gcc
CFLAGS = -g -Wall
LDFLAGS =
HOMEDIR = .
TARGET = reversestr

all: $(TARGET)

#test: $(OBJS)
#	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

reversestr: reversestr.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(HOMEDIR)/*.o $(TARGET)

.PHONY: all clean