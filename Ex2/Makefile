
CC=gcc
AR=ar
OBJECTS_MAIN= main.o myBank.o
FLAGS= -Wall

all: Program
Program:$(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o Program $^
main.o:main.c myBank.h
	$(CC) $(FLAGS) -c $^
myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -c $^

.PHONY:clean all

clean:
	rm *.o Program myBank.h.gch
