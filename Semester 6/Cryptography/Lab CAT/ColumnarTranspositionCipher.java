import java.util.*;

public class ColumnarTranspositionCipher {
    public static String removeSpaces(String str) {
        return str.replaceAll(" ", "");
    }

    public static String encrypt(String message, List<Integer> key) {
        StringBuilder ciphertext = new StringBuilder();
        int keySize = key.size();
        message = removeSpaces(message);
        
        while (message.length() % keySize != 0) {
            message += 'z';
        }
        
        for (int i = 0; i < message.length(); i += keySize) {
            char[] block = message.substring(i, i + keySize).toCharArray();
            char[] permutedBlock = new char[keySize];
            
            for (int j = 0; j < keySize; j++) {
                permutedBlock[j] = Character.toUpperCase(block[key.get(j) - 1]);
            }
            
            ciphertext.append(new String(permutedBlock));
        }
        return ciphertext.toString();
    }

    public static String decrypt(String ciphertext, List<Integer> key) {
        StringBuilder message = new StringBuilder();
        int keySize = key.size();
        
        for (int i = 0; i < ciphertext.length(); i += keySize) {
            char[] block = ciphertext.substring(i, i + keySize).toCharArray();
            char[] permutedBlock = new char[keySize];
            
            for (int j = 0; j < keySize; j++) {
                permutedBlock[key.get(j) - 1] = Character.toLowerCase(block[j]);
            }
            
            message.append(new String(permutedBlock));
        }
        return message.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the key: ");
        int n = scanner.nextInt();
        
        List<Integer> key = new ArrayList<>();
        System.out.print("Enter the key elements: ");
        for (int i = 0; i < n; i++) {
            key.add(scanner.nextInt());
        }
        scanner.nextLine(); // Consume the newline
        
        System.out.print("Enter the message: ");
        String message = scanner.nextLine();
        
        String ciphertext = encrypt(message, key);
        System.out.println("Ciphertext: " + ciphertext);
        
        String decryptedMessage = decrypt(ciphertext, key);
        System.out.println("Decrypted message: " + decryptedMessage);
        
        scanner.close();
    }
}