# Sorting Library
Description:
	The sorting library contains Bubble Sort, Shell Sort, Quick Sort using stacks, and Quick sort using queues. The reason why is because sorting items into a sorted order is one of the most common tasks in Computer Science and its important to understand how its done in order to make wise choices choosing algorithms for future programs.

## How To Run Program
```
make
```
- Used to build program
```
./sorting [-flag]
```
- Used to run test harness to test sort library
```
-a: Enables all sorting algorithms.
-b: Enable Bubble Sort.
-s: Enable Shell Sort.
-q: Enable the Quicksort that utilizes a stack.
-Q: Enable the Quicksort that utilizes a queue.
-r seed: Set the random seed to seed. The **default** is 13371453.
-n size: Set the array size to size. The **default** is 100.
-p elements: Print out elements number of elements from the array. The default is 100.
```
- Available flags.
---

## How to use Makefile
```
make
**or**
make all
```
- Used to build Program
```
make clean
```
- Used to removes all files that compiler generated.
```
make format
```
- Format all source code, including the header files.
