import java.util.Scanner;

public class AffineCipher {

    // Function to compute modular inverse of key1 under mod 26
    public static int modInverse(int key, int mod) {
        for (int i = 1; i < mod; i++) {
            if ((key * i) % mod == 1)
                return i;
        }
        return -1;
    }

    // Encryption function
    public static String encrypt(String plaintext, int key1, int key2) {
        StringBuilder ciphertext = new StringBuilder();
        for (char ch : plaintext.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = 'A';
                int p = Character.toUpperCase(ch) - base;
                int t = (p * key1) % 26;
                int c = (t + key2) % 26;
                ciphertext.append((char) (c + base));
            } else {
                ciphertext.append(ch);
            }
        }
        return ciphertext.toString();
    }

    // Decryption function
    public static String decrypt(String ciphertext, int key1, int key2) {
        StringBuilder plaintext = new StringBuilder();
        int inverseKey1 = modInverse(key1, 26);
        if (inverseKey1 == -1) {
            System.out.println("Error: Key1 has no modular inverse under modulo 26.");
            return "";
        }
        for (char ch : ciphertext.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = 'A';
                int c = ch - base;
                int t = (c - key2 + 26) % 26;  // Ensure positive value
                int p = (t * inverseKey1) % 26;
                plaintext.append((char) (p + base));
            } else {
                plaintext.append(ch);
            }
        }
        return plaintext.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter plaintext:");
        String plaintext = scanner.next();

        System.out.println("Enter key1:");
        int key1 = scanner.nextInt();

        System.out.println("Enter key2:");
        int key2 = scanner.nextInt();

        String ciphertext = encrypt(plaintext, key1, key2);
        System.out.println("Ciphertext: " + ciphertext);

        String decryptedText = decrypt(ciphertext, key1, key2);
        System.out.println("Decrypted Text: " + decryptedText);

        scanner.close();
    }
}
