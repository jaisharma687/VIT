import java.util.Scanner;

public class VigenereCipher {

    // Encrypt function for Vigenere Cipher
    public static String vigenereEncrypt(String plaintext, String key) {
        StringBuilder result = new StringBuilder();
        int keyIndex = 0;
        key = key.toUpperCase(); // Convert key to uppercase

        for (char p : plaintext.toCharArray()) {
            if (Character.isLetter(p)) {
                char upperP = Character.toUpperCase(p);
                int P = upperP - 'A';
                int K = key.charAt(keyIndex % key.length()) - 'A';
                result.append((char) ((P + K) % 26 + 'A'));
                keyIndex++;
            } else {
                result.append(p); // Keep non-alphabetic characters unchanged
            }
        }
        return result.toString();
    }

    // Decrypt function for Vigenere Cipher
    public static String vigenereDecrypt(String ciphertext, String key) {
        StringBuilder result = new StringBuilder();
        int keyIndex = 0;
        key = key.toUpperCase(); // Convert key to uppercase

        for (char c : ciphertext.toCharArray()) {
            if (Character.isLetter(c)) {
                char upperC = Character.toUpperCase(c);
                int C = upperC - 'A';
                int K = key.charAt(keyIndex % key.length()) - 'A';
                result.append((char) ((C - K + 26) % 26 + 'A'));
                keyIndex++;
            } else {
                result.append(c); // Keep non-alphabetic characters unchanged
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the key
        System.out.print("Enter the key: ");
        String key = scanner.nextLine();

        // Input the message
        System.out.print("Enter the message: ");
        String message = scanner.nextLine();

        System.out.println("Message: " + message);

        // Encrypt and decrypt
        String encrypted = vigenereEncrypt(message, key);
        System.out.println("Encrypted: " + encrypted);

        String decrypted = vigenereDecrypt(encrypted, key);
        System.out.println("Decrypted: " + decrypted);

        scanner.close();
    }
}
