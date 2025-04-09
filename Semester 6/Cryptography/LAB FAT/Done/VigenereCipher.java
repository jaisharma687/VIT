package Done;
import java.util.Scanner;

public class VigenereCipher {
    public static String vigenereEncrypt(String plaintext, String key) {
        StringBuilder result = new StringBuilder();
        int keyIndex = 0;
        key = key.toUpperCase();
        for (char p : plaintext.toCharArray()) {
            if (Character.isLetter(p)) {
                char upperP = Character.toUpperCase(p);
                int P = upperP - 'A';
                int K = key.charAt(keyIndex % key.length()) - 'A';
                result.append((char) ((P + K) % 26 + 'A'));
                keyIndex++;
            } else {
                result.append(p);
            }
        }
        return result.toString();
    }

    public static String vigenereDecrypt(String ciphertext, String key) {
        StringBuilder result = new StringBuilder();
        int keyIndex = 0;
        key = key.toUpperCase();
        for (char c : ciphertext.toCharArray()) {
            if (Character.isLetter(c)) {
                char upperC = Character.toUpperCase(c);
                int C = upperC - 'A';
                int K = key.charAt(keyIndex % key.length()) - 'A';
                result.append((char) ((C - K + 26) % 26 + 'A'));
                keyIndex++;
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the key: ");
        String key = scanner.nextLine();
        System.out.print("Enter the message: ");
        String message = scanner.nextLine();
        System.out.println("Message: " + message);
        String encrypted = vigenereEncrypt(message, key);
        System.out.println("Encrypted: " + encrypted);
        String decrypted = vigenereDecrypt(encrypted, key);
        System.out.println("Decrypted: " + decrypted);
        scanner.close();
    }
}
