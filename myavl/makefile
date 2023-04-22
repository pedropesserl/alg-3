CFLAGS = -Wall -Wextra -g

all: myavl

myavl: myavl.o
	gcc -o myavl myavl.o

myavl.o: myavl.c
	gcc -c myavl.c $(CFLAGS)

clean:
	-rm *.o

purge:
	-rm *.o myavl
