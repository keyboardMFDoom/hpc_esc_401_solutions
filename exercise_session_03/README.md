# Exercise Session 03 #
In this session, you will work on modularization of the code and compilation optimization. Moreover, you will parallelize a simple code and successively plot its speedup. 

In this folder you can find:

* cpi.c : the serial version of last week parallel code, needed for Exercise 1
* cpi_mpi.c : the MPI version of cpi code, for Exercise 1
* sum.c : the code needed for Exercise 2

# Solutions Arsenije Koljancic #

## Exercise 1 ##
- remarks:
	* compilation for the cpi_mpi file only worked with the cray compiler (cc)
	* instead of "gettime" I used "gt" to name the files

- OMP:
	* Execution time: ~1.503 seconds
	* Error: ~2 x 10^9

- MPI:
	* First execution time: ~1.529
	* First elapsed time with gt() function: ~2.4 
	* Error: ~2 x 10^9
	* All other execution times: ~1.503
	* All other elapsed times with gt() function: execution time + 0.002 seconds

- Possible reasons:
	* The gt function is outside the the inner code
	* In my case: compile using cc instead of gnu (optimization?)

- Results from different optimization flags
	* see results_optflags for the results
	* from "#include <time.h>" one could get clock(), time() or clock_gettime()
	* value is the same, time as expected: O0>O1>O2>O3 and difference:  4.925, 1.96, 1.089, 1.082. Optimizing as follows:
		- O1: Optimizing compilation takes somewhat more time, and a lot more memory for a large function.
		- O2: 
			•GCC performs nearly all supported optimizations that do not involve a space-speed tradeoff.
			•The compiler does not perform loop unrolling or function inlining when you specify -O2.
			•As compared to -O, this option increases both compilation time and the performance of the generated code.
		- O3:
			•Turns on all optimizations specified by -O2 and also turns on the -finline-functions,
			 -funswitch-loops, -fpredictive-commoning, -fgcse-after-reload and -ftree-vectorize options.
		- O0: Default, no optimization
	* adding -ffast-math would make it faster and adding -ffast-math -mavx2 would be the fastest (according to lecture 3, slide 23)
	* Interestingly I got the result when adding -ffast-math -mavx2 for every compilation the result was: O0>O2>O3>O1
