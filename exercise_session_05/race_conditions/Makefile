CFLAGS=-O3 -ffast-math -mavx2 -fopenmp
LDFLAGS=-fopenmp
CC=CC

all: serial.o serial
serial.o: serial.c num.txt
serial: serial.o serial
clean: 
	rm -f serial serial.o
