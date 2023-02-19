# Assignment 1 Question 4

## Compiling the source code

    To compile the java source code on Unix/Linux systems, open the terminal to this
    directory and type 
    ```
    javac server.java && javac client.java
    ```
	
## Running the compiled program

    To run the compiled program, open the terminal to this directory and type
    ```
    java server & 
    ```
    A message should display indicating that the process is running and a process ID is given to this process.
    You can verify the server process is running by typing the following command and searching for the java process.
    ```
    ps -l
    ```
    You can then run the client program by typing in the following command:
    ```
    java client
    ```
    If the connection to the server was successful, the client program will then prompt you to input a message. 
    Upon typing in any messages and pressing enter, the server will echo the same message back to the client.
    Exiting the program can be achieved by hitting Ctrl + C on the keyboard. Once the client has closed, you 
    should receive anothere message stating "Connection closed. Shutting down server."
    You can verify the server has closed by checking processes again, 
    ```
    ps -l
    ```