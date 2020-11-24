
CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=power.o basicMath.o
FLAGS= -Wall 

	
all: myMaths myMathd mains maind
mains:$(OBJECTS_MAIN) libmyMath.a
	$(CC) $(FLAGS) -o mains $^
maind:$(OBJECTS_MAIN) libmyMath.so
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyMath.so
myMaths:libmyMath.a
myMathd:libmyMath.so
main.o: main.c myMath.h
	$(CC) $(FLAGS) -c $^
libmyMath.a:$(OBJECTS_LIB) myMath.h
	$(AR) -rcs libmyMath.a $^
libmyMath.so:$(OBJECTS_LIB) myMath.h
	$(CC) -shared -o libmyMath.so $^

.PHONY: clean all

clean:
	rm  *.o *.so *.a mains maind
	
