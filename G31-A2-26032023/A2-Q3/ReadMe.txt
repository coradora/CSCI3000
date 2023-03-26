# Assignment 2 Question 3

## Compiling the source code

    To compile the source code on Unix/Linux systems, open the terminal to this
    directory and type 
    ```
    javac MonteCarloPi.java
    ```
	
## Running the compiled program

    To run the compiled program, open the terminal to this directory and type
    ```
    java MonteCarloPi
    ```
    
    The program then starts a new thread that generates random points and then
    calculates whether or not the randomly generated point falls within a circle
    using the (x^2 + y^2 <= r^2, where r = 1) calculation. If the point is in a circle,
    the thread increments the pointsInCircle variable. The totalPoints variable is
    also incremented regardless of if the point is in the circle. The main program then
    calculates an approximate number of pi with the (pi =~ 4 * pointsInCircle / totalPoints)
    calculation. The calculated approximation of pi is then output to the console.