# CUDA compiler
NVCC = nvcc
NVCCFLAGS = -O3 -arch=sm_90

# Host compiler (C)
CC = cc
CFLAGS = -O3

all: cpi_cuda

# Compile CUDA file
cpi_cuda.o: cpi_cuda.cu gettime.h
	$(NVCC) $(NVCCFLAGS) -c -o cpi_cuda.o cpi_cuda.cu

# Compile gettime.c using host compiler
gettime.o: gettime.c gettime.h
	$(CC) $(CFLAGS) -c -o gettime.o gettime.c

# Link executable using nvcc (must use nvcc!)
cpi_cuda: cpi_cuda.o gettime.o
	$(NVCC) $(NVCCFLAGS) -o cpi_cuda cpi_cuda.o gettime.o

clean:
	rm -f cpi_cuda *.o

