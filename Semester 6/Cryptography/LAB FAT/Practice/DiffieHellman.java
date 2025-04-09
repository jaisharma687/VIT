import java.math.*;
import java.util.*;

public class DiffieHellman {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger p = new BigInteger(sc.nextLine());
        BigInteger g = new BigInteger(sc.nextLine());
        BigInteger a = new BigInteger(sc.nextLine());
        BigInteger b = new BigInteger(sc.nextLine());
        BigInteger c = new BigInteger(sc.nextLine());
        BigInteger d = new BigInteger(sc.nextLine());
        BigInteger x = g.modPow(a, p);
        BigInteger y = g.modPow(b, p);
        BigInteger xh = g.modPow(c, p);
        BigInteger yh = g.modPow(d, p);
        System.out.println("x: "+x);
        System.out.println("y: "+y);
        System.out.println("xh: "+xh);
        System.out.println("yh: "+yh);
        // If no Middle Man
        System.out.println("If No Middle Man");
        BigInteger Ka = y.modPow(a, p);
        BigInteger Kb = x.modPow(b, p);
        System.out.println("Ka: "+Ka);
        System.out.println("Kb: "+Kb);

        // If Middle Man
        System.out.println("If Middle Man");
        Ka = y.modPow(c, p);
        Kb = x.modPow(d, p);
        System.out.println("Ka Hacker: "+Ka);
        System.out.println("Kb Hacker: "+Kb);
        Ka = yh.modPow(a, p);
        Kb = xh.modPow(b, p);
        System.out.println("Ka Alice: "+Ka);
        System.out.println("Kb Bob: "+Kb);
    }
}
