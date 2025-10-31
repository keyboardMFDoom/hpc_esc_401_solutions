#include "mpi.h"
#include <stdio.h>

//improvements concerning the syntax and use of functions corrected by ChatGPT
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes and rank of the process
    int size, my_rank;
    int tag=100;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Status status;

    int my_sum = 0;

    int send_rank = my_rank;  // Send    buffer
    int recv_rank = -1;        // Receive buffer

    // Compute the ranks of left/right neighbours 
    int right = (my_rank + 1) % size;
    int left = (my_rank - 1 + size) % size; //lowers costs and more general

    // Loop over the number of processes
    //     send to right, receive from left
    //     update the send buffer
    //     update the local sum
    for (int i = 0; i < size; i++) {
	MPI_Request reqs[2]; //if...else can be left out since nonblocking calls don't deadlock even if all ranks call I				//recv (from ChatGPT)
	MPI_Irecv(&recv_rank,1,MPI_INT,left,tag,MPI_COMM_WORLD,&reqs[0]);
        MPI_Isend(&send_rank, 1, MPI_INT,right,tag, MPI_COMM_WORLD,&reqs[1]);
	MPI_Waitall(2,reqs,MPI_STATUSES_IGNORE);
	my_sum+=recv_rank;
	send_rank = recv_rank;
}    
    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    // Finalize the MPI environment.
    MPI_Finalize();
}
