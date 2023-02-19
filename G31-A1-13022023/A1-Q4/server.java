import java.net.*;
import java.io.*;

public class server {
    public static void main(String[] args){
        try{
            ServerSocket socket = new ServerSocket(23456); // Creates serversocket and binds to port 23456
            while(true){
                Socket client = socket.accept(); // Creates client socket and accepts incoming connections.
                
                InputStream in = client.getInputStream(); // Instantiate an inputstream to read inputstream from client socket.
                BufferedReader bin = new BufferedReader(new InputStreamReader(in)); // Reads character streams from InputStream reader, guaranteeing byte level data.
                String line; // String to hold data to send back to the printwriter functions.
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true); // Instantiate a printwriter to write to the client socket output stream.

                // While there is data in the buffer, server will echo the same data back to the client.
                while( (line = bin.readLine()) != null) 
                {
                    System.out.println("Message to echo: " + line); // message to be sent back
                    pout.println(line); // Send message to client socket output stream
                    
                }

                // When InputStream's read() function == -1, client has disconnected from the server.
                if(in.read() == -1){
                    System.out.println("Connection closed. Shutting down server.");
                    break;
                }
            }   
        }

        catch (IOException error){
            System.err.println(error);
        }   
    }
}