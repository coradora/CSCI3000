// This program utilizes threads to generate fibonacci numbers. 
// Once a thread is created, the main process waits until the 
// thread has completed its operation before returning the 
// calculated fibonacci value depending on the user-input argument.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int fibonacci;
void *runner(void *param);
int calculate_fib(int i);

int main(int argc, char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);
    printf("The %d fibonacci value is: %d\n", atoi(argv[1]), fibonacci);
}

void *runner(void *param){
    int i = atoi(param);
    fibonacci = 0;
    fibonacci = calculate_fib(i); 
    pthread_exit(0);
}

int calculate_fib(int fib){ 
    for(int i = 0; i < fib; i++){
        if(fib == 0){
            return 0;
        }
        else if(fib == 1){
            return 1;
        }
        else{
            return(calculate_fib(fib - 1) + calculate_fib(fib - 2));
        }
    }
}