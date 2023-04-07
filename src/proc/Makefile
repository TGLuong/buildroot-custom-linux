.PHONY: all clean

CC ?= /usr/bin/gcc

OBJECT = proc.o

all: $(OBJECT)
	$(CC) -o main main.c $(OBJECT)
	$(CC) -o bai2 bai2.c $(OBJECT) -lpthread -lrt
	$(CC) -o proc1 proc1.c

proc.o: proc.c
	$(CC) -c proc.o proc.c

clean:
	rm *.o