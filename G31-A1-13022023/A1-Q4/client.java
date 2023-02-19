import java.net.*;
import java.io.*;
import java.util.Scanner;

public class client {
    public static void main(String[] args){
        try{
            Socket socket = new Socket("127.0.0.1", 23456);
            PrintWriter pout = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader bin = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            Scanner userInput = new Scanner(System.in);
            // Send messages the server to be echoed.
            System.out.println("Enter messages to be echoed by the server.");
            while(true){
                String message = userInput.nextLine();
                pout.println(message);
    
                // Receive message back from server.
                String line = bin.readLine();
                System.out.println("Server response: " + line);
            
            }
        }
        
        catch(IOException error){
            System.err.println(error);
        }
    }
}