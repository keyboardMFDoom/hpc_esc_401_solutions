#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes and rank of the process
    int size, my_rank,tag=100;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int my_sum = 0;

    int send_rank = my_rank;  // Send    buffer
    int recv_rank = 0;        // Receive buffer

    // Compute the ranks of left/right neighbours 
    int left_rank, right_rank;

    // Loop over the number of processes
    //     send to right, receive from left
    //     update the send buffer
    //     update the local sum
    for (int i = 0; i < size; i++) {
    	if (my_rank== 6) {
    		MPI_Ssend(my_rank,1,int,0,tag, comm)
	}else {
    		MPI_Ssend(my_rank,1,int,my_rank+1,tag, MPI_COMM_WORLD)
	}
	if (my_rank==0){
		MPI_Recv(my_rank,1,int,6,tag,comm)
	else {
		MPI_Recv(my_rank,1,int,my_rank-1,tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE)
	}
}
    
    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    // Finalize the MPI environment.
    MPI_Finalize();
}
