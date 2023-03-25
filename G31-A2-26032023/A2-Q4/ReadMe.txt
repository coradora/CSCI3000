# Assignment 2 Question 6

## Compiling the source code

    To compile the source code on Unix/Linux systems, open the terminal to this
    directory and type 
    ```
    javac DateClient.java DateServer.java 
    ```
	
## Running the compiled program

    To run the compiled program, open the terminal to this directory and type
    ```
    java DateServer &
    ```
    The DateServer should be running at this point and you can make requests
    to the DateServer with the following command:
    ```
    java DateClient
    ```
    The DateClient should print out the date provided by the DateServer. The
    DateServer will process each client connection and response on a separate thread.
    
    