import java.util.*;
public class ExponentProb {
    public static void Exponent(int x, int n){
        int exp = 1;
        for(int i = 1;i<=n;i++){
            exp = exp*x;
        }
        System.out.println(exp);
        return;
    }
    public static void main(String arg[]){
        Scanner input = new Scanner(System.in);
        int x = input.nextInt();
        int n = input.nextInt();
        Exponent(x, n);
    }
}
