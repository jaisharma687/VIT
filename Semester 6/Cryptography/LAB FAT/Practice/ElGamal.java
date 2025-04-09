import java.util.*;
import java.math.*;

public class ElGamal {
    public static BigInteger[] encrypt(BigInteger p, BigInteger g, BigInteger e, BigInteger pt, BigInteger n){
        BigInteger c1 = g.modPow(n,p);
        BigInteger c2 = e.modPow(n,p).multiply(pt).mod(p);
        return new BigInteger[] {c1, c2};
    }
    public static BigInteger decrypt(BigInteger d, BigInteger c1, BigInteger c2, BigInteger p){
        BigInteger s = c1.modPow(d, p);
        BigInteger sInv = s.modInverse(p);
        return c2.multiply(sInv).mod(p);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger p = new BigInteger(sc.nextLine());
        BigInteger g = new BigInteger(sc.nextLine());
        BigInteger d = new BigInteger(sc.nextLine());
        BigInteger n = new BigInteger(sc.nextLine());
        BigInteger pt = new BigInteger(sc.nextLine());
        BigInteger e = g.modPow(d, p);
        BigInteger[] c = encrypt(p, g, e, pt, n);
        System.out.println("C1: "+c[0]);
        System.out.println("C2: "+c[1]);
        pt = decrypt(d, c[0], c[1], p);
        System.out.println("PT: "+pt);
    }
}
