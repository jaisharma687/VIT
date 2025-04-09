package Done;
import java.math.BigInteger;
import java.security.*;

public class DSS {
    public static BigInteger hash(String message) throws Exception {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] digest = md.digest(message.getBytes());
        return new BigInteger(1, digest);
    }

    public static void main(String[] args) throws Exception {
        BigInteger p = new BigInteger("29");
        BigInteger q = new BigInteger("7");
        BigInteger g = new BigInteger("7");
        
        // Key generation
        BigInteger x = new BigInteger("3");
        BigInteger y = g.modPow(x, p); 
        
        System.out.println("DSA Parameters:");
        System.out.println("p = " + p);
        System.out.println("q = " + q);
        System.out.println("g = " + g);
        System.out.println("Private Key (x): " + x);
        System.out.println("Public Key (y): " + y);

        // Signing
        String message = "Hello DSS";
        BigInteger mHash = hash(message).mod(q);
        
        BigInteger k = new BigInteger("5");
        BigInteger r = g.modPow(k, p).mod(q);
        BigInteger kInv = k.modInverse(q);
        BigInteger s = kInv.multiply(mHash.add(x.multiply(r))).mod(q);

        System.out.println("\nSignature:");
        System.out.println("r = " + r);
        System.out.println("s = " + s);

        // Verification
        BigInteger w = s.modInverse(q);
        BigInteger u1 = mHash.multiply(w).mod(q);
        BigInteger u2 = r.multiply(w).mod(q);
        
        BigInteger v = g.modPow(u1, p).multiply(y.modPow(u2, p)).mod(p).mod(q);

        System.out.println("\nVerification Result:");
        System.out.println("Computed v: " + v);
        System.out.println("Original r: " + r);
        System.out.println(v.equals(r) ? "Valid signature!" : "Invalid signature!");
    }
}
