CC=gcc
CFLAGS=-Wall -Werror -Wextra 
# CFLAGS=-Wall -O1 -g -fopenmp
LDFLAGS=$(CFLAGS)

OBJ=$(patsubst %.c,%.o,$(wildcard *.c))

all: main
main: $(OBJ)

clean:
	rm $(OBJ) main

test: main
	./main 

