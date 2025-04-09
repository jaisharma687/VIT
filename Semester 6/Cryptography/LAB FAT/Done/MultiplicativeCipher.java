package Done;
import java.util.Scanner;

public class MultiplicativeCipher {

    // Function to compute modular inverse of key under mod 26
    public static int modInverse(int key, int mod) {
        for (int i = 1; i < mod; i++) {
            if ((key * i) % mod == 1)
                return i;
        }
        return -1;
    }

    // Encryption function
    public static String encrypt(String plaintext, int key) {
        StringBuilder ciphertext = new StringBuilder();
        for (char ch : plaintext.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = Character.isLowerCase(ch) ? 'a' : 'A';
                int p = ch - base;
                int c = (p * key) % 26;
                ciphertext.append((char) (c + 'A')); // Convert to uppercase
            } else {
                ciphertext.append(Character.toUpperCase(ch));
            }
        }
        return ciphertext.toString();
    }

    // Decryption function
    public static String decrypt(String ciphertext, int key) {
        StringBuilder plaintext = new StringBuilder();
        int inverseKey = modInverse(key, 26);
        if (inverseKey == -1) {
            System.out.println("Error: Key has no modular inverse under modulo 26.");
            return "";
        }
        for (char ch : ciphertext.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = Character.isLowerCase(ch) ? 'a' : 'A';
                int c = ch - base;
                int p = (c * inverseKey) % 26;
                if (p < 0) p += 26; // Ensure positive result
                plaintext.append((char) (p + 'A'));
            } else {
                plaintext.append(Character.toUpperCase(ch));
            }
        }
        return plaintext.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter plaintext:");
        String plaintext = scanner.next();

        System.out.println("Enter key:");
        int key = scanner.nextInt();

        String ciphertext = encrypt(plaintext, key);
        System.out.println("Ciphertext: " + ciphertext);

        String decryptedText = decrypt(ciphertext, key);
        System.out.println("Decrypted Text: " + decryptedText);

        scanner.close();
    }
}
