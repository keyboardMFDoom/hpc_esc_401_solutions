#include "mpi.h"
#include <stdio.h>
#define N 1000000000
int main(int argc, char** argv) {
    int i, rank, size, block_length, *values, data[N]
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    block_length = N/size
    
    int my_sum = 0;

    for(i=block_length*rank, i < i+block_length;++i)
   MPI_Gather(values,block_length,MPI_INTEGER,data,block_length,MPI_INTEGER, 0, MPI_COMM_WORLD);
   if (rank==0){
	printf("Total sum is");
	printf(my_sum)    
   // Finalize the MPI environment.
    MPI_Finalize();
}
