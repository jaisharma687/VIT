import java.util.*;
public class Transpose {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int matrix[][] = new int[n][m];
        for(int i=0; i<n; i++) {
             for(int j=0; j<m; j++) {
                 matrix[i][j] = sc.nextInt();
             }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                System.out.print(matrix[j][i]+" ");
            }
            System.out.println("");
       }
    }
}