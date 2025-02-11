import java.math.BigInteger;

public class RSA {
    public static void main(String args[]) {
        int p = 7, q = 11;
        int n = p * q;
        int z = (p - 1) * (q - 1);
        System.out.println("The value of z = " + z);

        int e;
        for (e = 2; e < z; e++) {
            if (e!=p && e!=q && gcd(e, z) == 1) { // Public key exponent
                break;
            }
        }
        System.out.println("The value of e = " + e);
        System.out.println("Public key is : (" + e + ", " + n + ")");
        int d;
        for(d=0;d<z;d++){
            if((d*e)%z==1){
                break;
            }
        }
        System.out.println("The value of d = " + d);
        System.out.println("Private key is : (" + d + ", " + n + ")");

        int msg = 4; // Message to encrypt

        // Encryption using BigInteger
        BigInteger N = BigInteger.valueOf(n);
        BigInteger E = BigInteger.valueOf(e);
        BigInteger D = BigInteger.valueOf(d);
        BigInteger M = BigInteger.valueOf(msg);

        // Encryption: C = M^e mod n
        BigInteger C = M.modPow(E, N);
        System.out.println("Encrypted message is : " + C);

        // Decryption: M = C^d mod n
        BigInteger decryptedMsg = C.modPow(D, N);
        System.out.println("Decrypted message is : " + decryptedMsg);
    }

    static int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
}
