# Assignment 2 Question 2

## Compiling the source code

    To compile the source code on Unix/Linux systems, open the terminal to this
    directory and type 
    ```
    gcc ./main.c -pthread
    ```
	
## Running the compiled program

    To run the compiled program, open the terminal to this directory and type
    ```
    ./a.out # 
    ```
    where # is any integer greater than or equal to zero.

    The program will then create a new thread, calculating the fibonaci sequence
    in a list up to the user provided argument (i.e. ./a.out 10 will output 
    the numbers "0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55").