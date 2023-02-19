import java.net.*;
import java.io.*;

public class server
{
    public static void main(String[] args){
        try{
            ServerSocket socket = new ServerSocket(23456);
            while(true){
                Socket client = socket.accept();
                // Instantiate an inputstream to read inputstream from client socket.
                InputStream in = client.getInputStream();
                // Receive message from the client.
                BufferedReader bin = new BufferedReader(new InputStreamReader(in));
                String line;
                // Instantiate a printwriter to write to the client socket output stream.
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true);

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