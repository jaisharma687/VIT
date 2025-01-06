import java.util.Scanner;

public class MultArray {
    public static void main(String arg[]){
        int[][] arr = {{1,1,1},{2,2,2},{3,3,3}};
        int[][] arr2 = {{1,1,1},{2,2,2},{3,3,3}};
        int[][] arr1 = new int[3][3];
        for(int i = 0; i<3;i++){
            for(int j=0;j<3;j++){
                arr1[i][j] = 0;
                for(int k=0;k<3;k++){
                    arr1[i][j]+=arr[i][k]*arr2[k][j];
                }
            }
        }
        for(int i = 0; i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print(arr1[i][j]+" ");
            }
            System.out.println();
        }
    }
}
