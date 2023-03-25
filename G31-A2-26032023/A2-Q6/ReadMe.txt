# Assignment 2 Question 6

## Compiling the source code

    To compile the source code on Unix/Linux systems, open the terminal to this
    directory (the directory containing this ReadMe.txt, not
    the Scheduling or Others directory) and type 
    ```
    javac -cp Others/:Scheduling/ Scheduling/Driver.java 
    ```
	
## Running the compiled program

    To run the compiled program, open the terminal to this directory and type
    ```
    java -cp Others/:Scheduling/ Scheduling/Driver.java ALG Scheduling/sched.txt 
    ```
    where ALG is any of the following scheduling algorithms:
    * FCFS
    * SJF
    * Pri 
    * RR

    The console should then output the tasks being performed in the proper
    order according to the scheduling algorithm based on the values in sched.txt.
    The first column indicates Task name, second column indicates Priority,
    and the third column indicates Burst time. 
    '''
    T1, 4, 20
    T2, 3, 25
    T3, 3, 25
    T4, 5, 15
    T5, 5, 20
    T6, 1, 10
    T7, 3, 30
    T8, 10, 25
    '''