# Exercise 11 Solutions Arsenije Koljancic
## Exercise 1
Yes, saving object files from temporary Directory to a Directory and creating PerfTools-instrumented executable.

According to the rpt file it's the main() function on line 40. Not sure but I think it's the calculaiton of the acceleration. Probably because it has to integrate all calculations together.

## Exercise 2
Before Adjustment:
real 0m16.522s

After sqrt Adjustment:
real 0m11.614s

Accoding to Stackoverflow sqrt() takes different types while sqrtf() only takes integers. So there is no ambiguity and the performance improves?

## Exercise 3
nbody.cpp:41:14: optimized: Basic block part vetorized using 32 Byte vectors:
- many blocks were optimized using "loop vectorized"

Difference:
nbody.cpp:41:14: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/vector.tcc:515:30: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/vector.tcc:96:27: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors

/usr/include/c++/12/bits/vector.tcc:699:31: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors

Fewer blocks needed to be optimized and some blocks were optimized twice. Tbh I didn't expect anything.

The time was
real 0m33.091s

## Exercise 4
Vector Report:
CC -O3 -fopt-info-vec -march=native -ffast-math -g -o nbody nbody.cpp
nbody.cpp:64:22: optimized: loop vectorized using 32 byte vectors
nbody.cpp:64:22: optimized: loop vectorized using 16 byte vectors
nbody.cpp:51:27: optimized: loop vectorized using 32 byte vectors
nbody.cpp:51:27: optimized: loop vectorized using 16 byte vectors
/usr/include/c++/12/bits/vector.tcc:699:31: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:412:42: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 16 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors

time was: real 0m14.634s

The loop is vectorized twice in different contexts.
## Exercise 5
