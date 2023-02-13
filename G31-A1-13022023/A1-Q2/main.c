#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
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
    // if pid == 0 (child), wait for parent execution to complete. (turns child process into a zombie process)
    else if (pid == 0){
        wait(NULL);
    }
    else{
	// parent process sleeps for 15 seconds. Child process is a zombie process through this execution. 
        sleep(15);
        printf("child process %ld killed.\n", pid);
    }

    return 0;
}
