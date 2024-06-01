all: client

client: main.o parser.o transform.o
    gcc -std=c99 -pedantic -Wall -o client main.o parser.o transform.o

main.o: main.c parser.h transform.h
    gcc -std=c99 -pedantic -Wall -c main.c

parser.o: parser.c parser.h
    gcc -std=c99 -pedantic -Wall -c parser.c

transform.o: transform.c transform.h parser.h
    gcc -std=c99 -pedantic -Wall -c transform.c

clean:
    rm -f client main.o parser.o transform.o
