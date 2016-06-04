README for assignennt 1, COMP 5421, summer 2016
Federico O'Reilly Regueiro 40012304
Concordia University

The folder contains the required cpp and h files plus a Makefile and a testing
driver. The makefile is thought out for the gnu compiler on a unix environment
and will output a driver executable and a tester executable. If the driver is
not compiled via the Makefile, having a preprocessor flag of NDEBUG is necessary
for the Nodes access modifiers to be compliant with the assignment requirements.
This is due to the need for fuller access to the nodes in the testing driver.

To run in a unix environment with the gnu compiler just run:
$ make
$ chmod u+x driver
$ ./driver
$ chmod u+x tester
$ ./tester

