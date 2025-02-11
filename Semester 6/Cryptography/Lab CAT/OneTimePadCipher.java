import java.util.Scanner;
import java.util.Random;

public class OneTimePadCipher {
    public static String xorEncryptDecrypt(String text, String key) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            result.append((char) (text.charAt(i) ^ key.charAt(i))); // XOR operation
        }
        return result.toString();
    }

    public static String generateRandomKey(int length) {
        Random rand = new Random();
        StringBuilder key = new StringBuilder();
        for (int i = 0; i < length; i++) {
            key.append((char) ('A' + rand.nextInt(26))); // Generate random uppercase letter (A-Z)
        }
        return key.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Get plaintext input
        System.out.print("Enter the plaintext: ");
        String plaintext = scanner.nextLine();
        
        // Generate a random key consisting only of uppercase letters (A-Z)
        String key = generateRandomKey(plaintext.length());
        
        // Encrypt the plaintext
        String ciphertext = xorEncryptDecrypt(plaintext, key);
        
        // Decrypt the ciphertext
        String decryptedText = xorEncryptDecrypt(ciphertext, key);

        // Print results
        System.out.println("Generated Key: " + key); // Key in alphabets
        System.out.println("Encrypted (Hex): " + toHex(ciphertext)); // Ciphertext in hexadecimal
        System.out.println("Decrypted Text: " + decryptedText);
        
        scanner.close();
    }

    private static String toHex(String text) {
        StringBuilder hex = new StringBuilder();
        for (char c : text.toCharArray()) {
            hex.append(String.format("%02X ", (int) c));
        }
        return hex.toString();
    }
}