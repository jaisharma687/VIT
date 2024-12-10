import java.util.*;

public class josephus{
    static int solve(int n, int k){
        if(n==1){
            return 1;
        }
        return (solve(n-1,k) + k-1)%n + 1;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        System.out.println(solve(n,k));
        scanner.close();
    }
}