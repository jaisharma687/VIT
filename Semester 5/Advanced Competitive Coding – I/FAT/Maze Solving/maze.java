import java.util.*;

public class maze {
    static boolean solve(int m,int n,int i,int j, int[][] arr, int[][] sol){
        if(i==m-1 && j==n-1){
            return true;
        }
        if(i>=m || j>=n) return false;
        if (i+1<m && arr[i+1][j]==1){
            sol[i+1][j] = 1;
            if(solve(m,n,i+1,j,arr,sol)){
                return true;
            }
            else sol[i+1][j] = 0;
        }
        if (j+1<n && arr[i][j+1]==1){
            sol[i][j+1] = 1;
            if(solve(m,n,i,j+1,arr,sol)){
                return true;
            }
            else sol[i+1][j] = 0;
        }
        return false;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[][] arr = new int[m][n];
        int[][] sol = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = scanner.nextInt();
                sol[i][j] = 0;
            }
        }
        sol[0][0] = 1;
        sol[m-1][n-1] = 1;
        System.out.println("Solution:");
        if(solve(m,n,0,0,arr,sol)){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    System.out.print(sol[i][j]+" ");
                }
                System.out.println("");
            }
        }
        scanner.close();
    }
}