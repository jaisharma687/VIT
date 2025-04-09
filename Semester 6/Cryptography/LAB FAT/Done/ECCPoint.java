import ECCPoint;
import ECCPoint.Point;

package Done;
public class ECCPoint {
    static final int p = 11;
    static final int a = 1;
    static final int b = 6;

    static class Point {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static int modInv(int base, int mod) {
        for (int d = 1; d < mod; d++) {
            if ((base * d) % mod == 1) return d;
        }
        return -1;
    }

    private static Point findPoints(int x1, int y1, int x2, int y2) {
        int lambda;
        if (x1 == x2 && y1 == y2) {
            int den = modInv(2 * y1, p);
            lambda = ((3 * x1 * x1 + a) * den) % p;
        } else {
            int dx = (x2 - x1 + p) % p;
            int dy = (y2 - y1 + p) % p;
            int den = modInv(dx, p);
            lambda = (dy * den) % p;
        }
        
        int x3 = (lambda * lambda - x1 - x2 + p) % p;
        int y3 = (lambda * (x1 - x3) - y1 + p) % p;
        return new Point((x3 + p) % p, (y3 + p) % p);
    }

    public static void main(String[] args) {
        int x1 = 2, y1 = 4;
        int x2 = 2, y2 = 7;
        
        Point result = findPoints(x1, y1, x2, y2);
        System.out.printf("{ %d, %d }\n", result.x, result.y);
        
        int lhs = (result.y * result.y) % p;
        int rhs = (result.x * result.x * result.x + a * result.x + b) % p;
        
        if (lhs == rhs) {
            System.out.println("It lies on the ECC curve");
        } else {
            System.out.println("Does not lie on the curve");
        }
    }
}
