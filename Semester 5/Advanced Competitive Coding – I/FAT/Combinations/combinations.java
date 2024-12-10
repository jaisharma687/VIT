import java.util.*;

public class combinations{
    static int factorial(int n){
        int res = 1;
        for(int i=2;i<=n;i++){
            res *= i;
        }
        return res;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        System.out.println(factorial(n) / (factorial(r) * factorial(n-r)));
        scanner.close();
    }
}
