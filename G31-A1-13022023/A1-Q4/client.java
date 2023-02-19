import java.net.*;
import java.io.*;
import java.util.Scanner;

public class client {
    public static void main(String[] args){
        try{
            Socket socket = new Socket("127.0.0.1", 23456); // Creates socket and attempts connection to server socket.
            PrintWriter pout = new PrintWriter(socket.getOutputStream(), true); // Instantiate a printwriter to write to the server socket output stream. 
            BufferedReader bin = new BufferedReader(new InputStreamReader(socket.getInputStream())); // Reads character streams from InputStream reader, guaranteeing byte level data.
            Scanner userInput = new Scanner(System.in); // Creates a scanner object to allow user to input data to be echoed by server.
            
            System.out.println("Enter messages to be echoed by the server.");
            while(true){
                String message = userInput.nextLine();
                pout.println(message); // Send messages the server to be echoed.
                String line = bin.readLine(); // Receive message back from server.
                System.out.println("Server response: " + line); // Output response to terminal.
            }
        }
        catch(IOException error){
            System.err.println(error);
        }
    }
}