### Result of different MM approaches

#### 1. Naive Implementation
The Idea: 
- Matices A, B and C are static. double for loop over rows of A and columns of B and the last nested for loop is for iterating every cell of the result matrix.

Measurements:

For N equal to:
- 128: 6ms
- 256: 66ms
- 512: 604ms
- 1024: SEGFAULT - 1024*1024 *3 ~ 12mb > stack_size


#### 2. Naive with Heap
The Idea:
- Previous one but we will use heap instead to allocate every array, because of small stack size. We will rerun the tests and see if we didnt make the time longer.

For N equal to:
- 128: 6ms
- 256: 66ms
- 512: 604ms
- 1024: 5_546ms
- 2048: 145_224 ms

#### 3. Compiler optimizations

The Idea:
At this we will use defined flags to speed up processor speed:

- -O3: biggest level of optimization
- -march=native: adjusts compiling for the cpu architetcure
- -ffast-math: aggresive assumptions with floating point numbers
- -funroll-loops: better with loops

effects:
For N equal to:
- 128: 0ms
- 256: 2ms
- 512: 32ms
- 1024: 236 ms
- 2048: 7_896 ms

#### 4. Transposing B
The Idea:
while iterating over columns we are jumping over n fields of the matrix, which requires more arithmetics. We transpose B and multiply the matrices by rows

For N equal to:

- 512: 13ms
- 1024: 113 ms
- 2048: 1_436 ms
#### 5. Cache Blocking
The Idea:
using Cache architecture to calculate different chunks aligned d continously. After calculating a chunk we will not go back to it.

For N equal to:

- 512: 9ms
- 1024: 110 ms
- 2048: 874 ms

# TODO nastepne proby
