# 2-Sum Problem Solver

This program solves the 2-Sum problem using various search algorithms. It reads a list of numbers from a file, sorts the list, and then finds two numbers whose sum equals a given target.

## Features

- Reads a list of numbers from a file
- Sorts the list of numbers
- Finds two numbers whose sum equals a given target using different search algorithms
- Measures the elapsed time for finding the solution

## Usage

1. Compile the program using a C compiler.
2. Prepare a file containing a list of numbers (each number separated by whitespace).
3. Run the compiled executable.
4. Enter the target sum.
5. Choose the search algorithm option (Linear Search, Binary Search, or Interpolation Search).
6. The program will output the combination of two numbers whose sum equals the target, along with the elapsed time for finding the solution.

## Search Algorithms

1. **Linear Search**: Simple search algorithm that checks each element in the list sequentially.
2. **Binary Search**: Efficient search algorithm for sorted lists that repeatedly divides the search interval in half.
3. **Interpolation Search**: Improved version of binary search that calculates the probable position of the target value.

## Notes

- The file containing the list of numbers should be formatted with each number separated by whitespace.
- Ensure that the file is present in the same directory as the executable.
- The program measures the elapsed time for finding the solution using the C `clock()` function.

