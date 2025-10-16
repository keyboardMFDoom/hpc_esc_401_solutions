# Exercise sheet 4 #
## Solutions Arsenije Koljancic ##

### Exercise 1 ###

- My permissions my:
	* $Scratch: drwxr-x---+ 2 akoljanc uzh8 4096 Oct 11 00:25 /capstor/scratch/cscs/akoljanc
	* $home: drwx------ 2 akoljanc uzh8 4096 Oct 16 23:58 /users/akoljanc

- My permissions for meberlei:
	* $Scratch: drwxr-x---+ 2 meberlei uzh8 4096 Oct 16 17:22 /capstor/scratch/cscs/meberlei
	* $home: drwx------ 2 meberlei uzh8 4096 Oct 16 17:35 /users/meberlei
	* /users/meberlei/exam_solutions.txt: Permission denied (if you work legally)

- Default for new files:
	* $Scratch: -rw-r-----+ 1 akoljanc uzh8 28 Oct 11 00:26 /capstor/scratch/cscs/akoljanc/test_perm_scratch
	* $home: -rw-r--r-- 1 akoljanc uzh8 25 Oct 11 00:23 /users/akoljanc/test_perm_home

- Changing permissions works as follows:
	* chmod 700 filename
	* chmod 070 /capstor/scratch/cscs/akoljanc/test_perm_scratch
	* No, I could still change the permission. But when chmod 000 was was I could "write" but it wasn't saved, 
	nor could I read it with cat test_perm_ex4.
