
LINES=6
TARGET=program
CC=gcc
OPT=0
CFLAGS=-ggdb3 -Wall -O$(OPT) -DCNT=$(LINES)
LDFLAGS=-lm

all: $(TARGET).out

$(TARGET).out: main.o fact.o combn.o pascal.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out main.o fact.o combn.o pascal.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

fact.o: fact.c
	$(CC) $(CFLAGS) -c fact.c

combn.o: combn.c
	$(CC) $(CFLAGS) -c combn.c

pascal.o: pascal.c
	$(CC) $(CFLAGS) -c pascal.c

clean:
	rm -f program.out main.o fact.o combn.o pascal.o

.PHONY: clean all

