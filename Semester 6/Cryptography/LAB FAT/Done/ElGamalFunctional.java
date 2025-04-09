package Done;
import java.math.BigInteger;
import java.util.Scanner;

public class ElGamalFunctional {

    // Encryption function
    public static BigInteger[] encrypt(BigInteger p, BigInteger g, BigInteger e, BigInteger message, BigInteger n) {
        BigInteger c1 = g.modPow(n, p);
        BigInteger c2 = e.modPow(n, p).multiply(message).mod(p);
        return new BigInteger[] {c1, c2};
    }

    // Decryption function
    public static BigInteger decrypt(BigInteger p, BigInteger d, BigInteger c1, BigInteger c2) {
        BigInteger s = c1.modPow(d, p);
        BigInteger sInverse = s.modInverse(p);
        return c2.multiply(sInverse).mod(p);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("ElGamal Encryption and Decryption (Functional Version)");
        System.out.println("======================================================");

        // Get cryptographic parameters
        System.out.print("Enter prime number (p): ");
        BigInteger p = new BigInteger(scanner.nextLine());
        
        System.out.print("Enter generator (g): ");
        BigInteger g = new BigInteger(scanner.nextLine());
        
        System.out.print("Enter private key (d): ");
        BigInteger d = new BigInteger(scanner.nextLine());

        // Calculate public key
        BigInteger e = g.modPow(d, p);
        System.out.println("Public key (e): " + e);

        // Get message and random number
        System.out.print("Enter message (numeric): ");
        BigInteger message = new BigInteger(scanner.nextLine());
        
        System.out.print("Enter random number (n): ");
        BigInteger n = new BigInteger(scanner.nextLine());

        // Perform encryption
        BigInteger[] ciphertext = encrypt(p, g, e, message, n);
        System.out.println("Ciphertext c1: " + ciphertext[0]);
        System.out.println("Ciphertext c2: " + ciphertext[1]);

        // Perform decryption
        BigInteger decrypted = decrypt(p, d, ciphertext[0], ciphertext[1]);
        System.out.println("Decrypted message: " + decrypted);
        
        scanner.close();
    }
}
