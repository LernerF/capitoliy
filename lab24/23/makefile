tree: lib.o tree.o
    gcc -o tree lib.o tree.o

tree.o: tree.c
    gcc --std=c99 --pedantic -Wall -c tree.c

lib.o: lib.c
    gcc --std=c99 --pedantic -Wall -c lib.c

clean:
    rm lib.o tree.o tree

all:
    gcc --std=c99 --pedantic -Wall -c lib.c
    gcc --std=c99 --pedantic -Wall -c tree.c
    gcc -o tree lib.o tree.o

run:
    gcc --std=c99 --pedantic -Wall -c lib.c
    gcc --std=c99 --pedantic -Wall -c tree.c
    gcc -o tree lib.o tree.o
    rm lib.o tree.o
    ./tree