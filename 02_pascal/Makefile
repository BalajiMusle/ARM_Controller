
all: program.out

program.out: main.o fact.o combn.o pascal.o
	gcc -ggdb2 -o program.out main.o fact.o combn.o pascal.o

main.o: main.c
	gcc -ggdb2 -c main.c

fact.o: fact.c
	gcc -ggdb2 -c fact.c

combn.o: combn.c
	gcc -ggdb2 -c combn.c

pascal.o: pascal.c
	gcc -ggdb2 -c pascal.c

clean:
	rm -f program.out main.o fact.o combn.o pascal.o

.PHONY: clean all

