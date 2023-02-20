# Assignment 1 Question 5

## Usage

    The program creates two pipes, which facilitates message transfer between a parent process and its
    child process. The parent process sends a message ("Hi There") which is read by the child through one pipe. The child then
    modifies the string (reverses the cases), and then sends the message on a second pipe. The parent process then
    reads the message through the second pipe.

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
    
    A message "hI tHERE" will appear in the terminal, indicating the program has executed successfully.

