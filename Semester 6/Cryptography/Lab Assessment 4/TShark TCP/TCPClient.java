import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient {
    private static final String HOST = "localhost";
    private static final int PORT = 5000;

    public static void main(String[] args) {
        try (Socket socket = new Socket(HOST, PORT);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            Scanner userInput = new Scanner(System.in)) {

            System.out.println("Connected to server at " + HOST + ":" + PORT);

            // Thread to receive server messages
            new Thread(() -> {
                try {
                    String serverResponse;
                    while ((serverResponse = in.readLine()) != null) {
                        System.out.println(serverResponse);
                    }
                } catch (IOException e) {
                    System.err.println("Error receiving server messages: " + e.getMessage());
                }
            }).start();

            // Send user input to server
            String userMessage;
            while (!(userMessage = userInput.nextLine()).equalsIgnoreCase("bye")) {
                out.println(userMessage);
            }
            out.println("bye");

        } catch (IOException e) {
            System.err.println("Client error: " + e.getMessage());
        }
    }
}
