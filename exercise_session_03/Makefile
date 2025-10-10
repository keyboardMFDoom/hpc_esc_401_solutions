CFLAGS=-Wall -O3 -ffast-math -mavx2 -fopenmp
LDFLAGS=-fopenmp
CC=gcc

sump: sump.o gt.o

sump.o: sump.c gt.h

clean:
	rm -f cpi cpi.o gt.o

