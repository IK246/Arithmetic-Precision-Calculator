compile.out: main.o addition.o subtraction.o multiplication.o division.o operation.o
	gcc -o compile.out main.o addition.o subtraction.o multiplication.o division.o operation.o
main.o: main.c
	gcc -c main.c
addition.o: addition.c
	gcc -c addition.c
subtraction.o: subtraction.c
	gcc -c subtraction.c
multiplication.o: multiplication.c
	gcc -c multiplication.c
division.o: division.c
	gcc -c division.c
operation.o: operation.c
	gcc -c operation.c
clean:
	rm *.o a.out
