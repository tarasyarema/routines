# WIP: routines comparison

This is a benchamrk/comparison repo to test different approaches for the same task: routines.

## dependecies

Install [boost](https://www.boost.org/). 
You may need to look for specific guidelines for your system.

> If you are using Ubuntu/Ubuntu based WSL, you only need `sudo apt install libboost-all-dev`.

## run

> You may need to change the `Makefile` if you are not in a linux environment.

Then just `make` to  run all the benchmarks.

## benchmarks

1. C++ boost::fibers
2. Go goroutines
3. C++ boost::thread
