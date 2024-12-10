import java.util.*;

public class maneuvering{
    static int solve(int i, int j, int m, int n){
        if(i==m-1 && j == n-1){
            return 1;
        }
        if(i>=m || j>=n) return 0;

        return solve(i+1,j,m,n) + solve(i,j+1,m,n);
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int paths = solve(0,0,m,n);
        System.out.println(paths);
        scanner.close();
    }
}