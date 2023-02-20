/*
    The following program creates two pipes, which facilitates message transfer between a parent process and its
    child process. The parent process sends a message which is read by the child through one pipe. The child then
    modifies the string (reverses the cases), and then sends the message on a second pipe. The parent process then
    reads the message through the second pipe.
*/

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

// defines constants for pipe functions for readability.
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main (void)
{
    char write_msg[BUFFER_SIZE] = "Hi There"; // Message to be updated
    char read_msg[BUFFER_SIZE];
    int pipe1[2]; // initialize file descriptor array for pipe 1, 0 = read, 1 = write
    int pipe2[2]; // initialize file descriptor array for pipe 2, 0 = read, 1 = write
    pid_t pid; // define pid as pid_t data type.

    // create pipes
    if(pipe(pipe1) == -1){
        // pipe() returns -1 if array is invalid or no available file descriptors
        fprintf(stderr, "Pipe failed"); // print error to stderr file
        return 1;
    }    
    if(pipe(pipe2) == -1){
        // pipe() returns -1 if array is invalid or no available file descriptors
        fprintf(stderr, "Pipe failed"); // print error to stderr file
        return 1;
    }    

    // fork child process
    pid = fork(); 
    if(pid < 0){
        // fork returns -1 if fork fails
        fprintf(stderr, 'Fork failed');
        return 1;
    }

    if (pid > 0){ // parent
        close(pipe1[READ_END]); // close read_end of pipe 1 (parent writes on pipe 1, reads on pipe 2)
        close(pipe2[WRITE_END]); // close the write end of pipe 2
        write(pipe1[WRITE_END], write_msg, strlen(write_msg) +1); // Write the message to be updated on pipe 1
        read(pipe2[READ_END], read_msg, BUFFER_SIZE); // Read the updated message from pipe 2
        printf("New message: %s\n", read_msg); // Print out the updated message
        close(pipe2[READ_END]); // Close the read end of pipe 2
        close(pipe1[WRITE_END]); // Close the write end of pipe 1
    }

    else{ // child
        read(pipe1[READ_END], read_msg, BUFFER_SIZE); // Read the initial message from pipe 1 (parent origin)
        close(pipe1[WRITE_END]); // close write_end of pipe 1 (child reads from pipe 1, writes on pipe 2)
        close(pipe2[READ_END]); // Close the read end of pipe 2
        char new_msg[BUFFER_SIZE] = {0}; // Initalize an empty array with same buffer_size of initial message..
        /* 
            The following for loop iterates through each character of the read_msg array (initial message),
            converting each lower-case letter into an upper-case letter and vice versa.
        */
        for(int i = 0; i < strlen(read_msg); i++){ 
            if(islower(read_msg[i]))
            {
                new_msg[i] = toupper(read_msg[i]);
            }
            else
            {
                new_msg[i] = tolower(read_msg[i]);
            }
        }
        write(pipe2[WRITE_END], new_msg, strlen(new_msg) +1); // Write the updated message to pipe 2's write end.
        close(pipe2[WRITE_END]); // Close pipe 2 write end
        close(pipe1[READ_END]); // Close pipe 1 read end
    }
    
    return 0;
}