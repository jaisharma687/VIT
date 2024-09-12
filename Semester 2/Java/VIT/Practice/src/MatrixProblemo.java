import java.util.*;
public class MatrixProblemo {
    static int[][] EnterMatrix(int[][] mat){
        Scanner obj = new Scanner(System.in);
        for(int i = 0; i<3;i++){
            for(int j = 0; j<3;j++){
                mat[i][j] = obj.nextInt();
            }
        }
        return mat;
    }
    static void PrintMatrix(int[][] A){
        for(int i = 0; i<3;i++){
            for(int j = 0; j<3;j++){
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }
    static int[][] AddMatrix(int[][] B, int[][] C){
        int[][] sum = new int[3][3];
        for(int i = 0; i<3;i++){
            for(int j = 0; j<3;j++){
                sum[i][j] = C[i][j] + B[i][j];
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        int[][] a = new  int[3][3];
        int[][] b = new  int[3][3];
        EnterMatrix(a);
        EnterMatrix(b);
        PrintMatrix(a);
        PrintMatrix(b);
        PrintMatrix(AddMatrix(b, a));
    }
}
