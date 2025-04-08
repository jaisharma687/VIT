import java.io.*;
import java.net.*;
import java.util.*;
import javax.crypto.*;
import javax.crypto.spec.*;
import java.security.*;

public class SimpleSSHServer {
    private static final int PORT = 2222;
    private static final String SECRET_KEY = "secretkey";
    private static Map<String, String> users = new HashMap<>();
    
    static {
        users.put("jai", "jaisharma27");
    }
    
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("SSH Server started on port " + PORT);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());
                new Thread(() -> handleClient(clientSocket)).start();
            }
        } catch (IOException e) {
            System.err.println("Server error: " + e.getMessage());
        }
    }
    
    private static void handleClient(Socket clientSocket) {
        try (
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)
        ) {
            out.println("SSH-2.0-SimpleSSH_0.1");
            String clientVersion = in.readLine();
            System.out.println("Client version: " + clientVersion);
            
            out.println("Please enter username:");
            String username = in.readLine();
            out.println("Please enter password:");
            String password = in.readLine();
            
            if (authenticateUser(username, password)) {
                out.println("Authentication successful");
                boolean running = true;
                while (running) {
                    out.println("Enter command (or 'exit' to quit):");
                    String command = in.readLine();
                    if ("exit".equalsIgnoreCase(command)) {
                        running = false;
                        out.println("Goodbye!");
                    } else {
                        String result = executeCommand(command);
                        out.println("RESULT:" + result);
                    }
                }
            } else {
                out.println("Authentication failed");
            }
            
        } catch (IOException e) {
            System.err.println("Error handling client: " + e.getMessage());
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                System.err.println("Error closing socket: " + e.getMessage());
            }
        }
    }
    
    private static boolean authenticateUser(String username, String password) {
        return users.containsKey(username) && users.get(username).equals(password);
    }
    
    private static String executeCommand(String command) {
        try {
            if (command.startsWith("echo ")) {
                return command.substring(5);
            } else if (command.equals("date")) {
                return new Date().toString();
            } else if (command.equals("whoami")) {
                return System.getProperty("user.name");
            } else if (command.equals("pwd")) {
                return System.getProperty("user.dir");
            } else {
                return "Command not supported. Try: echo, date, whoami, pwd";
            }
        } catch (Exception e) {
            return "Error executing command: " + e.getMessage();
        }
    }
}