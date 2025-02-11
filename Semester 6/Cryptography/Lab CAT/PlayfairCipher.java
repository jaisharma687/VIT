import java.util.*;

public class PlayfairCipher {

    private static final int SIZE = 5;

    // Generate a 5x5 key matrix for Playfair Cipher
    public static char[][] generateKeyMatrix(String key) {
        Set<Character> used = new HashSet<>();
        char[][] keyMatrix = new char[SIZE][SIZE];
        StringBuilder processedKey = new StringBuilder();

        // Process the key (convert to uppercase, replace J with I, and remove duplicates)
        for (char c : key.toUpperCase().toCharArray()) {
            if (c == 'J') c = 'I';
            if (Character.isLetter(c) && used.add(c)) {
                processedKey.append(c);
            }
        }

        // Fill the key matrix with key characters
        int index = 0;
        for (char c : processedKey.toString().toCharArray()) {
            keyMatrix[index / SIZE][index % SIZE] = c;
            index++;
        }

        // Fill remaining positions with unused letters (excluding J)
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c == 'J') continue;
            if (used.add(c)) {
                keyMatrix[index / SIZE][index % SIZE] = c;
                index++;
            }
        }
        return keyMatrix;
    }

    // Find the position of a character in the key matrix
    public static int[] findPosition(char[][] keyMatrix, char c) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (keyMatrix[i][j] == c) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1};
    }

    // Prepare plaintext by converting to uppercase, replacing 'J' with 'I', and inserting 'Z' if needed
    public static String prepareText(String text) {
        StringBuilder prepared = new StringBuilder();
        for (char c : text.toUpperCase().toCharArray()) {
            if (Character.isLetter(c)) {
                prepared.append(c == 'J' ? 'I' : c);
            }
        }

        // Insert 'Z' between duplicate letters or at the end if odd length
        for (int i = 0; i < prepared.length(); i += 2) {
            if (i + 1 == prepared.length() || prepared.charAt(i) == prepared.charAt(i + 1)) {
                prepared.insert(i + 1, 'Z');
            }
        }
        return prepared.toString();
    }

    // Encrypt or decrypt the text using Playfair Cipher rules
    public static String processText(String text, char[][] keyMatrix, boolean encrypt) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < text.length(); i += 2) {
            int[] pos1 = findPosition(keyMatrix, text.charAt(i));
            int[] pos2 = findPosition(keyMatrix, text.charAt(i + 1));

            if (pos1[0] == pos2[0]) {  // Same row
                result.append(keyMatrix[pos1[0]][(pos1[1] + (encrypt ? 1 : 4)) % SIZE]);
                result.append(keyMatrix[pos2[0]][(pos2[1] + (encrypt ? 1 : 4)) % SIZE]);
            } else if (pos1[1] == pos2[1]) {  // Same column
                result.append(keyMatrix[(pos1[0] + (encrypt ? 1 : 4)) % SIZE][pos1[1]]);
                result.append(keyMatrix[(pos2[0] + (encrypt ? 1 : 4)) % SIZE][pos2[1]]);
            } else {  // Rectangle swap
                result.append(keyMatrix[pos1[0]][pos2[1]]);
                result.append(keyMatrix[pos2[0]][pos1[1]]);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the keyword
        System.out.println("Enter keyword:");
        String key = scanner.nextLine();
        char[][] keyMatrix = generateKeyMatrix(key);

        // Display the generated key matrix
        System.out.println("\nGenerated Key Matrix:");
        for (char[] row : keyMatrix) {
            for (char c : row) {
                System.out.print(c + " ");
            }
            System.out.println();
        }

        // Get the plaintext
        System.out.println("\nEnter message to encrypt:");
        String plaintext = scanner.nextLine();

        plaintext = prepareText(plaintext);
        String encryptedText = processText(plaintext, keyMatrix, true);
        System.out.println("\nEncrypting...\nThe encrypted text is: " + encryptedText);

        String decryptedText = processText(encryptedText, keyMatrix, false);
        System.out.println("\nDecrypting...\nThe decrypted text is: " + decryptedText);

        scanner.close();
    }
}
