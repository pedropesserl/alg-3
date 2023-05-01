CFLAGS = -Wall -Wextra -g

all: myavl

myavl: myavl.o lib_avl.o
	gcc -o myavl myavl.o lib_avl.o

myavl.o: myavl.c lib_avl.h
	gcc -c myavl.c $(CFLAGS)

teste: teste_avl.o lib_avl.o
	gcc -o teste_avl teste_avl.o lib_avl.o

teste_avl.o: teste_avl.c lib_avl.h
	gcc -c teste_avl.c $(CFLAGS)

clean:
	-rm *.o

purge:
	-rm *.o myavl teste_avl
