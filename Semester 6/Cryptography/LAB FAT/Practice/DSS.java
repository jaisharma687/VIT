import java.math.*;

public class DSS {
    public static void main(String[] args) throws Exception {
        BigInteger m = BigInteger.valueOf(50);

        BigInteger p = BigInteger.valueOf(283);
        BigInteger q = BigInteger.valueOf(47);
        BigInteger g = BigInteger.valueOf(60);

        BigInteger x = BigInteger.valueOf(24);
        BigInteger y = g.modPow(x, p);

        System.out.println("DSA Parameters:");
        System.out.println("p = " + p);
        System.out.println("q = " + q);
        System.out.println("g = " + g);
        System.out.println("Private Key (x): " + x);
        System.out.println("Public Key (y): " + y);

        //Signatue
        BigInteger k = BigInteger.valueOf(15);
        BigInteger r = g.modPow(k, p).mod(q);
        BigInteger s = k.modInverse(q).multiply(m.add(x.multiply(r))).mod(q);

        System.out.println("\nSignature:");
        System.out.println("r = " + r);
        System.out.println("s = " + s);

        //Verification
        BigInteger w = s.modInverse(q);
        BigInteger u1 = m.multiply(w).mod(q);
        BigInteger u2 = r.multiply(w).mod(q);
        BigInteger v = (g.modPow(u1, p).multiply(y.modPow(u2, p))).mod(p).mod(q);

        System.out.println("\nVerification Result:");
        System.out.println("w: " + w);
        System.out.println("u1: " + u1);
        System.out.println("u2: " + u2);
        System.out.println("Computed v: " + v);
        System.out.println("Original r: " + r);

        System.out.println(v.equals(r) ? "Valid signature!" : "Invalid signature!");
    }
}
