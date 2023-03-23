// This program utilizes threads to generate fibonacci numbers. 
// Once a thread is created, the main process waits until the 
// thread has completed its operation before returning the 
// calculated fibonacci value depending on the user-input argument.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Globals 
int fibonacci;
int *fibb_num[0];

// function forward declarations
void *runner(void *param);
int calculate_fib(int fib);

int main(int argc, char *argv[]){
    // if argc (argument count) is not equal to 2, too many arguments.
    if(argc != 2){
        fprintf(stderr, "Need only one argument.\n");
        return 1;
    }

    // if user input < 0 (negative integer), return error and error message.
    if(atoi(argv[1]) < 0){
        fprintf(stderr, "Please enter a positive integer.\n");
        return 1;
    }

    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, (argv[1]));

    // wait until thread operation completes before displaying calculation to user.
    pthread_join(tid, NULL);
    for(int i = 0; i < atoi(argv[1]); i++){
        printf("%d, ", fibb_num[i]);
    }
    printf("%d\n", fibonacci);
}

void *runner(void *param){
    int i = atoi(param);
    // allocate size of array to number to calculate
    int *fibb_num = malloc(i * sizeof *fibb_num);
    
    fibonacci = 0;
    fibonacci = calculate_fib(i); 
    pthread_exit(0);
}

int calculate_fib(int fib){ 
    if (fib == 0){
        fibb_num[0] = 0;
        return 0;
    }
    else if (fib == 1){
        fibb_num[1] = 1;
        return 1;
    }
    else{
        int calc = calculate_fib(fib - 1) + calculate_fib(fib - 2);
        fibb_num[fib] = calc;
        return calc;
    }
}