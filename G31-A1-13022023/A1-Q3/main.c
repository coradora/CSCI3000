/*
    This program takes in a positive integer as an argument, and performs a calculation until the value
    is equal to 1. For example, the number 35 will return 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1
    If multiple arguments are passed, or a negative integer is entered, an error will be returned and the program will exit.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    // argv[0] = name of program
    // argv[1] = first argument passed

    // convert argv[1] (char) to an integer
    int num = atoi(argv[1]);
    
    // if argc (argument count) is not equal to 2, too many arguments.
    if(argc != 2){
        fprintf(stderr, "Need only one argument.\n");
        return 1;
    }

    // if num < 0 (negative integer), return error and error message.
    if(num < 0){
        fprintf(stderr, "Please enter a positive integer.\n");
        return 1;
    }
    
    // instantiate a pid_t variable named pid 
    pid_t pid;
    // assign pid variable to forked child's pid
    pid = fork();
    // error handling if pid is invalid/out of range. 
    if (pid < 0){
	// fprintf specifies to write "fork failed" error to stderr, return 1 indicates error while executing program
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    // child process, perform calculations.
    else if (pid == 0){
        while(num != 1){ // If number does not equal 1
            printf("%i, ", num); // print out current number before calculation
            if(num % 2 == 0){       // if number is even, divide by 2
                num = num / 2;
            }
            else if(num % 2 == 1){  // if number is odd, multiply by three and add 1.
                num = 3 * num + 1;
            }   
        }
        printf("%i \n", num); // should be 1, print out 1. 
    }
    else{
	// parent process waits for child to complete execution
        wait(NULL);
    }

    return 0;
}

