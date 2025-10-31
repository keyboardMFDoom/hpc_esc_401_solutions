#include "mpi.h"
#include <stdio.h>

//improvements concerning the syntax and use of functions corrected by ChatGPT
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    int MPI_Cart_create(
    MPI_Comm comm_old, // old communicator
    int ndims, // number of dimensions of the grid
    int *dims, // integer array of size ndims, specifies
    // the number of processes in each dim.
    int *periods, // logical array of size ndims specifying
    // whether the grid is periodic (true) or
    // not (false) in each dimension
    int reorder, // ranking may be reordered (1) or not (0)
    // (logical)
    MPI_Comm *comm_cart); // new cartesian communicator

    // Get the number of processes and rank of the process
    MPI_Cart_create(MPI_Comm, 1,  
    

    int my_sum = 0;

    int send_rank = my_rank;  // Send    buffer
    int recv_rank = -1;        // Receive buffer

    // Compute the ranks of left/right neighbours 
    int MPI_Cart_shift(
	MPI_Comm comm, // communicator with cartesian structure
	int direction, // coordinate dimension of shift (integer)
	int displ, // displacement (>0: upwards shift,
	// <0: downwards shift (integer)
	int *source, // rank of source process (integer)
	int *dest); // rank of destination process (integer)

    // Loop over the number of processes
    //     send to right, receive from left
    //     update the send buffer
    //     update the local sum
    for (int i = 0; i < size; i++) {
	MPI_Cart_shift
	//MPI_Request reqs[2]; //if...else can be left out since nonblocking calls don't deadlock even if all ranks call I				//recv (from ChatGPT)
	//MPI_Irecv(&recv_rank,1,MPI_INT,left,tag,MPI_COMM_WORLD,&reqs[0]);
        //MPI_Isend(&send_rank, 1, MPI_INT,right,tag, MPI_COMM_WORLD,&reqs[1]);
	//MPI_Waitall(2,reqs,MPI_STATUSES_IGNORE);
	//my_sum+=recv_rank;
	//send_rank = recv_rank;
}    
    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    // Finalize the MPI environment.
    MPI_Finalize();
}
