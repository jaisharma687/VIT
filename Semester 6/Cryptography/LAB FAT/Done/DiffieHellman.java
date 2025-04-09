package Done;
import java.math.BigInteger;
import java.util.Scanner;

public class DiffieHellman {
    private static BigInteger p;
    private static BigInteger g;

    static class Party {
        final String name;
        BigInteger privateKey;
        BigInteger publicKey;
        BigInteger sharedSecret;

        public Party(String name, BigInteger privateKey) {
            this.name = name;
            this.privateKey = privateKey;
            this.publicKey = g.modPow(privateKey, p);
        }

        public void receive(BigInteger received, String from) {
            sharedSecret = received.modPow(privateKey, p);
            System.out.printf("[%s] Received %2d from %-10s | Shared secret: %2d\n", 
                            name, received, from, sharedSecret);
        }
    }

    static class Middleman {
        BigInteger privateKeyForAlice;
        BigInteger privateKeyForBob;
        BigInteger publicKeyForAlice;
        BigInteger publicKeyForBob;

        public Middleman(BigInteger privateForAlice, BigInteger privateForBob) {
            this.privateKeyForAlice = privateForAlice;
            this.privateKeyForBob = privateForBob;
            this.publicKeyForAlice = g.modPow(privateForAlice, p);
            this.publicKeyForBob = g.modPow(privateForBob, p);
        }

        public void interceptAliceToBob(Party Alice, Party Bob) {
            System.out.printf("\n[MITM] Replaced Alice's %2d with %2d to Bob\n", 
                            Alice.publicKey, publicKeyForBob);
            Bob.receive(publicKeyForBob, "MITM-Alice");
        }

        public void interceptBobToAlice(Party Bob, Party Alice) {
            System.out.printf("[MITM] Replaced Bob's %2d with %2d to Alice\n", 
                            Bob.publicKey, publicKeyForAlice);
            Alice.receive(publicKeyForAlice, "MITM-Bob");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter prime modulus (p): ");
        p = new BigInteger(scanner.nextLine());
        
        System.out.println("Enter generator (g): ");
        g = new BigInteger(scanner.nextLine());

        System.out.println("\nEnter private keys:");
        System.out.print("Alice's private key: ");
        Party Alice = new Party("Alice", new BigInteger(scanner.nextLine()));
        
        System.out.print("Bob's private key: ");
        Party Bob = new Party("Bob", new BigInteger(scanner.nextLine()));

        System.out.println("\nEnter Middleman's private keys:");
        System.out.print("Private key for Alice: ");
        BigInteger mitmPrivateForAlice = new BigInteger(scanner.nextLine());
        
        System.out.print("Private key for Bob: ");
        BigInteger mitmPrivateForBob = new BigInteger(scanner.nextLine());
        
        Middleman mitm = new Middleman(mitmPrivateForAlice, mitmPrivateForBob);

        printKeys("\nInitial Keys:", Alice, Bob);
        printMitmKeys("\nMiddleman's Keys:", mitm);

        System.out.println("\n\n--- Normal Exchange ---");
        Bob.receive(Alice.publicKey, "Alice");
        Alice.receive(Bob.publicKey, "Bob");
        printSecrets("Legitimate Shared Secrets:", Alice, Bob);

        System.out.println("\n\n--- MITM Attack ---");
        mitm.interceptAliceToBob(Alice, Bob);
        mitm.interceptBobToAlice(Bob, Alice);
        printSecrets("\nCompromised Shared Secrets:", Alice, Bob);
    }

    private static void printKeys(String header, Party... parties) {
        System.out.println(header);
        for(Party p : parties) {
            System.out.printf("%-7s | Private: %2d | Public: %2d\n", 
                            p.name, p.privateKey, p.publicKey);
        }
    }

    private static void printMitmKeys(String header, Middleman mitm) {
        System.out.println(header);
        System.out.printf("For Alice | Private: %2d | Public: %2d\n", 
                        mitm.privateKeyForAlice, mitm.publicKeyForAlice);
        System.out.printf("For Bob   | Private: %2d | Public: %2d\n", 
                        mitm.privateKeyForBob, mitm.publicKeyForBob);
    }

    private static void printSecrets(String header, Party... parties) {
        System.out.println(header);
        for(Party p : parties) {
            System.out.printf("%-7s | Secret: %2d\n", p.name, p.sharedSecret);
        }
    }
}
