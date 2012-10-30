CC = gcc
CFLAGS = -g -I../lib -L../lib -Wall -O3

project: mylib.o source.o
	$(CC) $(CFLAGS) -o project $^ -lm
mylib.o: 
	$(CC) $(CFLAGS) -c ../lib/mylib.c 
source.o: 
	$(CC) $(CFLAGS) -c source.c
clean:
	rm *.o project
