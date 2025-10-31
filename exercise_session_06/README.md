### Exercise sheet 6 Solutions Arsenije Koljancic ###

## Ex1
- The code stuck and didn't print any statemant
- In my words (correct me if I'm wrong): Every process waits till another process does something, this process in turn waits for another process to do a certain task and so forth. By blocking send/receive resources are allocated but not used.
- The first code didn't function since it did exactly the deadlock, whereas the new implementation help to work around the deadlock
- Not optimal (from ChatGPT): problems if topology is changed, synchronizing (timing is strict), parity trick (better use MPI_Sencrecv), fragile if one process crashes
- Why Irecv-Isend-Waitall is better: The Waitall function makes sure that that jobs are finished before moving on.

## Ex2
-   
