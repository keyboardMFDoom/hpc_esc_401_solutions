CC = cc
CFLAGS = -O3 -acc -gpu=cc90
LDFLAGS = -acc -gpu=cc90

all: cpi_openacc

cpi_openacc.o: cpi_openacc.c gettime.h
	$(CC) $(CFLAGS) -c -o cpi_openacc.o cpi_openacc.c

gettime.o: gettime.c gettime.h
	$(CC) $(CFLAGS) -c -o gettime.o gettime.c

cpi_openacc: cpi_openacc.o gettime.o
	$(CC) $(LDFLAGS) -o cpi_openacc cpi_openacc.o gettime.o

clean:
	rm -f cpi_openacc *.o

