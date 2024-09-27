all: compl_client
  valgrind --leak-check=yes -s ./client

compl_client: main.c table.c iterator.c
  gcc -std=c99 -pedantic -Wall -o client main.c table.c iterator.c

clean:
  rm -f table.o
  rm -f client