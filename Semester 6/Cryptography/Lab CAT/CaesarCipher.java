import java.util.Scanner;

public class CaesarCipher {

    public static String caesarEncrypt(String s, int key) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            int ascii = s.charAt(i) - 'a';
            int newAscii = (ascii + key) % 26;
            char newChar = (char) (newAscii + 'A');
            res.append(newChar);
        }
        return res.toString();
    }

    public static void caesarDecrypt(String s) {
        for (int key = 1; key < 26; key++) {
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                int ascii = s.charAt(i) - 'A';
                int newAscii = (ascii + key) % 26;
                char newChar = (char) (newAscii + 'A');
                res.append(newChar);
            }
            System.out.println("Key: " + key + " -> Decrypted Text: " + res);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the plain text: ");
        String plainText = scanner.next();

        System.out.println("Enter the key: ");
        int key = scanner.nextInt();

        String cipherText = caesarEncrypt(plainText, key);
        System.out.println("Cipher Text: " + cipherText);
        System.out.println("Decrypted Text: ");
        caesarDecrypt(cipherText);

        scanner.close();
    }
}
