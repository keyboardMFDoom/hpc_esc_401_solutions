# Solutions Exercise 5 Arsenije Koljancic#

## Exercise 1 ##
I'm still learning C/C++ so for programming exercises that don't use Python I still use ChatGPT. In this context I used it to get the routines init_f, jacobi_step and norm_diff.
- init_f: initializing the matrix with the interior and boundrary conditions. From the exercise description and plot it was visible that the initial matrix was 1 for 0.25<x<0.75 and y=0, else 0
- jacobi_step: implementation of the jacobi solver i.e. use the stencil at (i,j) with old values to get u_new(i,j)
- norm_diff: to see if the difference of abs(u_old-u_new) put into the equation is lower than the tolerance

## Exercise 2 ##
- By eye the results look similar. I run the job script three times:
	*ompnp1: just to see if it works without the #pragma put into place
	*omp1: #pragma put in place and run on 1 thread
	*omp4: #pragma put in place and run on 4 threads

## Exercise 3 ##
not finished but it showed the same output if I put #pragma before both loops. Probably shouldve run it more often to really confirm this statement.
