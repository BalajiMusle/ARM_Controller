
LINES=6
TARGET=program
CC=gcc
OPT=0
CFLAGS=-ggdb3 -Wall -Werror -O$(OPT) -DCNT=$(LINES)
LDFLAGS=-lm

all: start build end

start:
	@echo "***** started build process *****"

end:
	@echo "***** finished build process *****"

build: $(TARGET).out

$(TARGET).out: main.o fact.o combn.o pascal.o
	@echo "-- linking --> $^ to create $@ --"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

main.o: main.c
	@echo "-- compiling --> $< --"
	$(CC) $(CFLAGS) -c $<

fact.o: fact.c
	@echo "-- compiling --> $< --"
	$(CC) $(CFLAGS) -c $<

combn.o: combn.c
	@echo "-- compiling --> $< --"
	$(CC) $(CFLAGS) -c $<

pascal.o: pascal.c
	@echo "-- compiling --> $< --"
	$(CC) $(CFLAGS) -c $<

clean:
	@echo "-- deleting .o files and .out files --"
	rm -f program.out main.o fact.o combn.o pascal.o

.PHONY: clean all start build end

