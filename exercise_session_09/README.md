# Exercise sheet 9 Solutions Arsenije Koljancic
## Exercise 1
- Execution time GPU vs CPU:
	Execution time of openmp is much faster than of openACC by the order of nearly 10^6. By increasing the size of 		the problem, the execution times increase as well. Maybe it's because the GPU takes longer for memory transfer 
	or such a simple task is not suited for GPUs. 

## Exercise 2
- Problem with the approach:

- Difference between blur_twice_gpu_naive vs blur_twice_gpu_nocopies:

- Execution time:

## Exercise 3
- Reason for race conditions:
	The loop after the TODO is not synchronized. Therefore each thread writes to the same variable.
- The keyword:
	reduction (+:sum) as in OpenMP

- Difference in performance between GPU and CPU:
	Again the CPU seems to be faster than the GPU by a magnitude of 10^5. Except for one example but there I didn't 	modify anything so it's probably an error. I'm quite unsure if I really did it right.
 
Makefile:10: extraneous text after 'ifeq' directive
nvc++ -I../common -O3 -acc -mp -Minfo=acc -std=c++11 -gpu=cc90 dot_openacc.cpp -o dot.openacc
dot_gpu(double const*, double const*, int):
     23, Loop is parallelizable
         Generating NVIDIA GPU code
         23, #pragma acc loop gang, vector(128) /* blockIdx.x threadIdx.x */
             Generating implicit reduction(+:sum)
     23, Generating implicit copy(sum) [if not already present]
         Generating implicit copyin(x[:n],y[:n]) [if not already present]

Makefile:10: extraneous text after 'ifeq' directive
nvc++ -I../common -O3 -acc -mp -Minfo=acc -std=c++11 -gpu=cc90 dot_openacc.cpp -o dot.openacc
dot_gpu(double const*, double const*, int):
     23, Generating copy(sum) [if not already present]
         Generating copyin(y[:n],x[:n]) [if not already present]
         Generating implicit firstprivate(n)
         Generating NVIDIA GPU code
         23, #pragma acc loop gang, vector(128) /* blockIdx.x threadIdx.x */
             Generating reduction(+:sum)

My questions:
- what's the problem with using #pragma acc kernels? doesn't it as well make sure that it's copied to the host?
