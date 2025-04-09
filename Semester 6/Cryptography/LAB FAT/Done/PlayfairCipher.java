package Done;
import java.util.*;

public class PlayfairCipher {
    private static final int SIZE = 5;
    public static char[][] generateKeyMatrix(String key) {
        Set<Character> used = new HashSet<>();
        char[][] keyMatrix = new char[SIZE][SIZE];
        StringBuilder processedKey = new StringBuilder();
        for (char c : key.toUpperCase().toCharArray()) {
            if (c == 'J') c = 'I';
            if (Character.isLetter(c) && used.add(c)) {
                processedKey.append(c);
            }
        }
        int index = 0;
        for (char c : processedKey.toString().toCharArray()) {
            keyMatrix[index / SIZE][index % SIZE] = c;
            index++;
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c == 'J') continue;
            if (used.add(c)) {
                keyMatrix[index / SIZE][index % SIZE] = c;
                index++;
            }
        }
        return keyMatrix;
    }

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

    public static String prepareText(String text) {
        StringBuilder prepared = new StringBuilder();
        for (char c : text.toUpperCase().toCharArray()) {
            if (Character.isLetter(c)) {
                prepared.append(c == 'J' ? 'I' : c);
            }
        }
        for (int i = 0; i < prepared.length(); i += 2) {
            if (i + 1 == prepared.length() || prepared.charAt(i) == prepared.charAt(i + 1)) {
                prepared.insert(i + 1, 'Z');
            }
        }
        if (prepared.length() % 2 != 0) {
            prepared.append('Z');
        }
        return prepared.toString();
    }

    public static String processText(String text, char[][] keyMatrix, boolean encrypt) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < text.length(); i += 2) {
            int[] pos1 = findPosition(keyMatrix, text.charAt(i));
            int[] pos2 = findPosition(keyMatrix, text.charAt(i + 1));
            if (pos1[0] == pos2[0]) {
                result.append(keyMatrix[pos1[0]][(pos1[1] + (encrypt ? 1 : 4)) % SIZE]);
                result.append(keyMatrix[pos2[0]][(pos2[1] + (encrypt ? 1 : 4)) % SIZE]);
            } else if (pos1[1] == pos2[1]) {
                result.append(keyMatrix[(pos1[0] + (encrypt ? 1 : 4)) % SIZE][pos1[1]]);
                result.append(keyMatrix[(pos2[0] + (encrypt ? 1 : 4)) % SIZE][pos2[1]]);
            } else {
                result.append(keyMatrix[pos1[0]][pos2[1]]);
                result.append(keyMatrix[pos2[0]][pos1[1]]);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter keyword (letters only):");
        String key = scanner.nextLine().trim();

        char[][] keyMatrix = generateKeyMatrix(key);

        System.out.println("\nGenerated Key Matrix:");
        for (char[] row : keyMatrix) {
            for (char c : row) {
                System.out.print(c + " ");
            }
            System.out.println();
        }

        System.out.println("\nEnter message to encrypt:");
        String plaintext = scanner.nextLine();
        plaintext = prepareText(plaintext);
        
        System.out.println("\nPrepared Text: " + plaintext);

        String encryptedText = processText(plaintext, keyMatrix, true);
        System.out.println("\nEncrypting...\nThe encrypted text is: " + encryptedText);

        String decryptedText = processText(encryptedText, keyMatrix, false);
        System.out.println("\nDecrypting...\nThe decrypted text is: " + decryptedText);
    }
}
