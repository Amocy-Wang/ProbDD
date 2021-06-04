# ChiselBench

## Getting Started
Once you have [Chisel](https://github.com/aspire-project/chisel) installed,
make sure it is in the PATH.

Next, clone ChiselBench, and run the following command in its main directory:
```
$ . setenv
```
By running `make reduce` in each of subdirectories of the `benchmark` directory,
Chisel will start the reduction. 


## Benchmark Structure
Under the `benchmark` directory, there are separate folders for each program.
Each folder contains three main elements:

* A `*.origin.c` which is the original program (before reduction).
* A test script (`test.sh`) in which the desired and undesired features are
specified as well as all the Clang Sanitizers and erroneous environment
simulators against which the user might want to test the program.
* A `Makefile` for making life easier.

Other files or folders that are inside each subdirectory, only support the test script.
