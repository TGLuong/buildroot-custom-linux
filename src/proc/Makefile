.PHONY: all clean

CC ?= /usr/bin/gcc

OBJECT = main.o proc.o

all: $(OBJECT)
	$(CC) -o main $(OBJECT)
	$(CC) -o proc1 proc1.c

main.o: main.c
	$(CC) -c main.o main.c

proc.o: proc.c
	$(CC) -c proc.o proc.c

clean: