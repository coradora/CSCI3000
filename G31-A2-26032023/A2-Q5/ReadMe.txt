# Assignment 2 Question 5

## Compiling the source code

    To compile the source code on Unix/Linux systems, open the terminal to this
    directory and type 
    ```
    g++ ./A2-Q5.cpp -pthread
    ```
	
## Running the compiled program

    To run the compiled program, open the terminal to this directory and type
    ```
    ./a.out #  
    ```
    where # is any number of integers (at least one integer)

    The program will then create three new threads, calculating the
    max number, min number, and mean of the numbers provided as an argument.
    For example,

    ```
    ./a.out 12 4 8
    ```

    will output 
    
    ```
    Minimum number is 4
    Maximum number is 12
    Mean number is 8
    ```
