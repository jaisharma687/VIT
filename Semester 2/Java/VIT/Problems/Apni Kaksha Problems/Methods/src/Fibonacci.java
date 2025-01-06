import java.util.*;
public class Fibonacci {
    public static int Fib(int n){
        if(n<=1){
            return n;
        }
        return Fib(n-1)+Fib(n-2);
    }
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(Fib(n));
    }
}
