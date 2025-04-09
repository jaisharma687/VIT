package Done;
import java.util.*;

public class HillCipher {
    
    private static final int K = 26;

    // Function to find modular inverse of 'a' under modulo 'm'
    public static int modInverse(int a, int m) {
        for (int x = 1; x < m; ++x) {
            if ((a * x) % m == 1) {
                return x;
            }
        }
        return -1;
    }

    // Matrix multiplication (mod 26)
    public static int[] multiplyMatrix(int[][] key, int[] text) {
        int[] result = new int[3];
        for (int i = 0; i < 3; i++) {
            result[i] = 0;
            for (int j = 0; j < 3; j++) {
                result[i] += key[i][j] * text[j];
            }
            result[i] %= K;
        }
        return result;
    }

    // Prepare plaintext (convert to uppercase, remove spaces, and pad with 'X')
    public static String prepareText(String text) {
        StringBuilder prepared = new StringBuilder();
        for (char c : text.toUpperCase().toCharArray()) {
            if (Character.isLetter(c)) {
                prepared.append(c);
            }
        }
        while (prepared.length() % 3 != 0) {
            prepared.append('X');
        }
        return prepared.toString();
    }

    // Encrypt the text using Hill Cipher
    public static String encrypt(String text, int[][] key) {
        StringBuilder ciphertext = new StringBuilder();
        for (int i = 0; i < text.length(); i += 3) {
            int[] plainVec = {text.charAt(i) - 'A', text.charAt(i + 1) - 'A', text.charAt(i + 2) - 'A'};
            int[] cipherVec = multiplyMatrix(key, plainVec);
            for (int val : cipherVec) {
                ciphertext.append((char) (val + 'A'));
            }
        }
        return ciphertext.toString();
    }

    // Compute the inverse of a 3x3 matrix modulo 26
    public static int[][] inverseKeyMatrix(int[][] key) {
        int det = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
                  key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
                  key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);

        det = (det % K + K) % K;
        int detInverse = modInverse(det, K);

        if (detInverse == -1) {
            System.out.println("Key matrix is not invertible. Decryption not possible.");
            return null;
        }

        int[][] adj = new int[3][3];
        adj[0][0] = (key[1][1] * key[2][2] - key[1][2] * key[2][1]) % K;
        adj[0][1] = (key[0][2] * key[2][1] - key[0][1] * key[2][2]) % K;
        adj[0][2] = (key[0][1] * key[1][2] - key[0][2] * key[1][1]) % K;
        adj[1][0] = (key[1][2] * key[2][0] - key[1][0] * key[2][2]) % K;
        adj[1][1] = (key[0][0] * key[2][2] - key[0][2] * key[2][0]) % K;
        adj[1][2] = (key[0][2] * key[1][0] - key[0][0] * key[1][2]) % K;
        adj[2][0] = (key[1][0] * key[2][1] - key[1][1] * key[2][0]) % K;
        adj[2][1] = (key[0][1] * key[2][0] - key[0][0] * key[2][1]) % K;
        adj[2][2] = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % K;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                adj[i][j] = (adj[i][j] * detInverse % K + K) % K;
            }
        }
        return adj;
    }

    // Decrypt the text using Hill Cipher
    public static String decrypt(String text, int[][] key) {
        int[][] inverseKey = inverseKeyMatrix(key);
        if (inverseKey == null) return "";

        StringBuilder plaintext = new StringBuilder();
        for (int i = 0; i < text.length(); i += 3) {
            int[] cipherVec = {text.charAt(i) - 'A', text.charAt(i + 1) - 'A', text.charAt(i + 2) - 'A'};
            int[] plainVec = multiplyMatrix(inverseKey, cipherVec);
            for (int val : plainVec) {
                plaintext.append((char) (val + 'A'));
            }
        }
        return plaintext.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input plaintext
        System.out.print("Enter the Plain text for Encryption: ");
        String text = scanner.nextLine();
        text = prepareText(text);
        System.out.println("Padded Text: " + text);

        // Key matrix
        int[][] key = {
            {6, 24, 1},
            {13, 16, 10},
            {20, 17, 15}
        };

        // Print key matrix
        System.out.println("Key Matrix:");
        for (int[] row : key) {
            System.out.println(Arrays.toString(row));
        }

        // Encrypt and decrypt
        String encrypted = encrypt(text, key);
        System.out.println("Encrypted Message: " + encrypted);

        String decrypted = decrypt(encrypted, key);
        System.out.println("Decrypted Message: " + decrypted);

        scanner.close();
    }
}
