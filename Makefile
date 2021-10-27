# Makefile for ex1-q1 winter 2019A
CFLAGS = -Wall
LDFLAGS = -lm # not really needed for this exercise
CC = gcc -std=c99
ECHO = echo "going to compile for target $@"
PROG = ex1_q1

all: $(PROG) test

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

Settings.o: Settings.c Settings.h
	$(CC) $(CFLAGS) -c Settings.c

ex1_q1.o: ex1_q1.c 
	$(CC) $(CFLAGS) -c ex1_q1.c

ex1_q1: ex1_q1.o Settings.o list.o
	$(CC) -o $(PROG)  $(CFLAGS) ex1_q1.o Settings.o list.o
test: $(PROG)
	@echo going to run test

clean:
	rm -v *.o $(PROG)