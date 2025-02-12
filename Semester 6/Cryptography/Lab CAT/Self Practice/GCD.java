import java.util.*;

public class GCD {
    public int gcd(int a, int b){
        if(a==b){
            return a;
        }
        else if(a>b){
            return gcd(a-b,b);
        }
        return gcd(a,b-a);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = 12;
        int b = 8;
        GCD g = new GCD();
        System.out.println(g.gcd(a,b));
        sc.close();
    }
}
