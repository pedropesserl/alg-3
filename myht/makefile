CFLAGS = -Wall -Wextra -g
OBJ = myht.o libchash.o
DEPS = libchash.h
LINK = -lm


%.o: %.c $(DEPS)
	gcc $(CFLAGS) -o $@ -c $< $(LINK)

all: myht

myht: $(OBJ) $(DEPS)
	gcc -o $@ $(OBJ) $(LINK)

clean:
	rm -f $(OBJ)

purge:
	rm -rf $(OBJ) myht
