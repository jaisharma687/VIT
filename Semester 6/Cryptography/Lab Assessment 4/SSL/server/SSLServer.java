package server;

import javax.net.ssl.*;
import java.io.*;
import java.security.*;

public class SSLServer {
    private static final int PORT = 1234;

    public static void main(String[] args) {
        try {
            char[] password = "18122020".toCharArray();
            KeyStore keyStore = KeyStore.getInstance("JKS");

            try (FileInputStream fis = new FileInputStream("server.keystore")) {
                keyStore.load(fis, password);
            }

            KeyManagerFactory kmf = KeyManagerFactory.getInstance("SunX509");
            kmf.init(keyStore, password);

            SSLContext sslContext = SSLContext.getInstance("TLS");
            sslContext.init(kmf.getKeyManagers(), null, null);

            SSLServerSocketFactory ssf = sslContext.getServerSocketFactory();

            try (SSLServerSocket serverSocket = (SSLServerSocket) ssf.createServerSocket(PORT)) {
                System.out.println("Server started. Waiting for client...");

                try (SSLSocket clientSocket = (SSLSocket) serverSocket.accept()) {
                    System.out.println("Client connected.");

                    try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)) {

                        String message;
                        while ((message = in.readLine()) != null) {
                            System.out.println("Received from client: " + message);
                            out.println("Server received: " + message);
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}