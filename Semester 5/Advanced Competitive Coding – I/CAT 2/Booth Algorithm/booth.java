import java.math.*;
import java.util.*;

public class booth {
    public static void main(String arg[]){
        Scanner input = new Scanner(System.in);
        BigInteger n1 = input.nextBigInteger();
        BigInteger n2 = input.nextBigInteger();
        System.out.println(n1.multiply(n2));
        input.close();
    }
}