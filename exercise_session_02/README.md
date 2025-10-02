# Exercise Session 02 #
In this session, you will compile and run your first programs on Eiger. This directory contains two versions of the code that were parallelized using MPI or OpenMP.

## Exercise sheet 2 ##

### Exercise 1 ###
- During the cloning no problems arised.
- Status is up to date and log showed only the initial repository

### Exercise 2 ###
- cc:
- O3:
- O0:
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
- still woring on
