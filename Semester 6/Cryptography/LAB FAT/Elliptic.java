import java.math.BigInteger;
import java.util.Scanner;

public class Elliptic {
    private final BigInteger a, b, p;

    public Elliptic(BigInteger a, BigInteger b, BigInteger p) {
        this.a = a;
        this.b = b;
        this.p = p;
    }

    private static class Point {
        public final BigInteger x, y;
        public static final Point INFINITY = new Point(null, null);

        public Point(BigInteger x, BigInteger y) {
            this.x = x;
            this.y = y;
        }

        public boolean isInfinity() {
            return this.x == null && this.y == null;
        }

        @Override
        public boolean equals(Object obj) {
            if (!(obj instanceof Point)) return false;
            Point other = (Point) obj;
            return (this.x == null && other.x == null) || (this.x.equals(other.x) && this.y.equals(other.y));
        }

        @Override
        public String toString() {
            return isInfinity() ? "Infinity" : "(" + x + "," + y + ")";
        }
    }

    private Point add(Point P, Point Q) {
        if (P.isInfinity()) return Q;
        if (Q.isInfinity()) return P;
        if (P.x.equals(Q.x) && P.y.equals(Q.y.negate().mod(p))) return Point.INFINITY;

        BigInteger m;
        if (P.equals(Q)) {
            BigInteger num = P.x.pow(2).multiply(BigInteger.valueOf(3)).add(a);
            BigInteger den = P.y.multiply(BigInteger.valueOf(2)).modInverse(p);
            m = num.multiply(den).mod(p);
        } else {
            BigInteger num = Q.y.subtract(P.y);
            BigInteger den = Q.x.subtract(P.x).modInverse(p);
            m = num.multiply(den).mod(p);
        }

        BigInteger x3 = m.pow(2).subtract(P.x).subtract(Q.x).mod(p);
        BigInteger y3 = m.multiply(P.x.subtract(x3)).subtract(P.y).mod(p);
        return new Point(x3, y3);
    }

    private Point subtract(Point P, Point Q) {
        // To subtract Q from P, we add P and the inverse of Q
        if (Q.isInfinity()) return P;
        Point negQ = new Point(Q.x, Q.y.negate().mod(p));
        return add(P, negQ);
    }

    private Point multiply(Point P, BigInteger k) {
        Point result = Point.INFINITY;
        Point temp = P;

        while (k.signum() > 0) {
            if (k.testBit(0)) result = add(result, temp);
            temp = add(temp, temp);
            k = k.shiftRight(1);
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter curve parameters (a, b, p):");
        BigInteger a = scanner.nextBigInteger();
        BigInteger b = scanner.nextBigInteger();
        BigInteger p = scanner.nextBigInteger();
        
        System.out.println("Curve equation: y^2 = x^3 + " + a + "x + " + b + " (mod " + p + ")");
        elliptic curve = new elliptic(a, b, p);
        
        System.out.println("Enter generator point G (x, y):");
        BigInteger gx = scanner.nextBigInteger();
        BigInteger gy = scanner.nextBigInteger();
        Point G = new Point(gx, gy);
        System.out.println("Generator point G: " + G);
        
        System.out.println("Enter message point Pm (x, y):");
        BigInteger pmx = scanner.nextBigInteger();
        BigInteger pmy = scanner.nextBigInteger();
        Point Pm = new Point(pmx, pmy);
        System.out.println("Message point Pm: " + Pm);
        
        System.out.println("Enter scalar k (used for both private key and encryption):");
        BigInteger k = scanner.nextBigInteger();
        System.out.println("Scalar k: " + k);
        
        // Calculate public key PB = k*G
        Point PB = curve.multiply(G, k);
        System.out.println("Public key PB = k*G: " + PB);
        
        System.out.println("\n--- ENCRYPTION ---");
        Point C1 = curve.multiply(G, k);  // C1 = k*G (same as PB in this case)
        Point C2 = curve.add(Pm, curve.multiply(PB, k));  // C2 = Pm + k*PB = Pm + k*(k*G)
        
        System.out.println("Encrypted point C1 = k*G: " + C1);
        System.out.println("Encrypted point C2 = Pm + k*PB: " + C2);
        
        System.out.println("\n--- DECRYPTION ---");
        // Decryption: Pm = C2 - k*C1
        Point kC1 = curve.multiply(C1, k);
        Point decryptedPm = curve.subtract(C2, kC1);
        System.out.println("Decrypted point Pm = C2 - k*C1: " + decryptedPm);
        
        // Verify if decryption is correct
        boolean isDecryptionCorrect = decryptedPm.x.equals(Pm.x) && decryptedPm.y.equals(Pm.y);
        System.out.println("Decryption " + (isDecryptionCorrect ? "successful! Original message recovered." : "failed!"));
        
        scanner.close();
    }
}
