# Makefile for assignment no. #1

all: ex1q1

list.o: list.c list.h
	gcc -Wall -c list.c

Settings.o: Settings.c Settings.h
	gcc -Wall -c Settings.c

ex1_q1.o: ex1_q1.c 
	gcc -Wall -c ex1_q1.c

ex1q1: ex1_q1.o Settings.o list.o
	gcc -o ex1q1 -Wall ex1_q1.o Settings.o list.o
clean:
	rm -v *.o ex1q1 