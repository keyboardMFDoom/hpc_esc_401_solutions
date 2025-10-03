# Exercise Session 02 #
In this session, you will compile and run your first programs on Eiger. This directory contains two versions of the code that were parallelized using MPI or OpenMP.

## Exercise sheet 2 ##

### Exercise 1 ###
- During the cloning no problems arised.
- Status is up to date and log showed only the initial repository

### Exercise 2 ###
- cc: Compiler for C files. Man cc didn't really help but the lecture slides.
- O0: Default of optimization choice. No optimization.
- O3: From slide 24 -
 	Everything from O2:
 		- perform all supported optimizations which do not involve space-speed tradeoff
 		- not involving loop unrolling or function inlining when -O2 is specified
 		- increase of compilation time and the Performance of the generated code
 	Plus:
 		- finline-functions
 		- funswitch-loops
 		- fpredictive-commoning
 		- fgcs-after-reload
 		- ftree-vectorize options
- current environment: is cray 23.12 the default?
- module list: list of loaded modules
- module avail: shows currently loaded modules (more specific than module list?)
- module spider: shows the available modules and extensions on cscs

### Exercise 3 ###
- sinfo -p debug shows the partitions called debug. I could see my jobs which were submitted with the command 
squeue -u akoljanc. For other jobs it's squeue -u username, I guess.
- for the errors log and the output log I had to add #SBATCH -e omp-%j.err and #SBATCH -o omp-%j.out.
- -cpu-bind=none: (if I did it right) accuracy was the same, running time was slightly faster 
- to get the output from squeue I specify: squeue -u akoljanc --format "%.A %.u %.p %.a %.j %D %t %r %S %L %p"

### Exercise 4 ###
- I ran "SLURM_CPUS_PER_TASK=1 and 10", if that's right then 1 was the slowest, 128 was in the middle and 10 was the fastest. Does that make sense?
- changing to O0: it took way longer (approx. 24 second) and the precision was bad like 10 to the power of 7.

