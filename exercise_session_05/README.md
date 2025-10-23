# Solutions Exercise 5 Arsenije Koljancic#

## Exercise 1 ##
I'm still learning C/C++ so for programming exercises that don't use Python I still use ChatGPT. In this context I used it to get the routines init_f, jacobi_step and norm_diff.
- init_f: initializing the matrix with the interior and boundrary conditions. From the exercise description and plot it was visible that the initial matrix was 1 for 0.25<x<0.75 and y=0, else 0
- jacobi_step: implementation of the jacobi solver i.e. use the stencil at (i,j) with old values to get u_new(i,j)
- norm_diff: to see if the difference of abs(u_old-u_new) put into the equation is lower than the tolerance


