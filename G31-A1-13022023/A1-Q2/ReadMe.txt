# Assignment 1 Question 2

## Compiling the source code

    To compile the source code on Unix/Linux systems, open the terminal to this
    directory and type 
    ```
    gcc ./main.c
    ```
	
## Running the compiled program

    To run the compiled program, open the terminal to this directory and type
    ```
    ./a.out
    ```
    After fifteen seconds, a message will appear indicating the child process has been killed.

    To verify this, we can type in the following command (tested on Ubuntu 20.04 LTS)
    ```
    time ./a.out & ps - l
    ```
    This command will indicate the parent process and a list of running processes. 
    The child process will be indicated as a child underneath the PPID column. Underneath the 
    S column, the child column will be indicated as a 'Z', or a zombie process.
