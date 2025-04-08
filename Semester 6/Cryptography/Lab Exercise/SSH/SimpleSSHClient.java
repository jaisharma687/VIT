import java.io.*;
import java.net.*;
import java.util.*;
import javax.crypto.*;
import javax.crypto.spec.*;
import java.security.*;

public class SimpleSSHClient {
    private static final int PORT = 2222;
    private static final String HOST = "localhost";
    private static final String SECRET_KEY = "secretkey";
    
    public static void main(String[] args) {
        try (
            Socket socket = new Socket(HOST, PORT);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in))
        ) {
            String serverVersion = in.readLine();
            System.out.println("Server: " + serverVersion);
            out.println("SSH-2.0-SimpleSSHClient_0.1");
            String usernamePrompt = in.readLine();
            System.out.print(usernamePrompt + " ");
            String username = userInput.readLine();
            out.println(username);

            String passwordPrompt = in.readLine();
            System.out.print(passwordPrompt + " ");
            String password = userInput.readLine();
            out.println(password);
            
            String authResult = in.readLine();
            System.out.println("Server: " + authResult);
            
            if (authResult.contains("successful")) {
                boolean running = true;
                while (running) {
                    String prompt = in.readLine();
                    System.out.print("Server: " + prompt + " ");
                    
                    String command = userInput.readLine();
                    out.println(command);
                    
                    if ("exit".equalsIgnoreCase(command)) {
                        String goodbye = in.readLine();
                        System.out.println("Server: " + goodbye);
                        running = false;
                    } else {
                        String result = in.readLine();
                        if (result.startsWith("RESULT:")) {
                            System.out.println(result.substring(7));
                        } else {
                            System.out.println(result);
                        }
                    }
                }
            }
            
        } catch (IOException e) {
            System.err.println("Client error: " + e.getMessage());
        }
    }
}