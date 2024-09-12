//JAI SHARMA
//22BEE0191
import java.util.*;
public class PAT21 {
    public static int[][] getMatrix(int[][] arr) {
        Scanner sct = new Scanner(System.in);
        for(int i =0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                arr[i][j] =sct.nextInt();
            }
        }
        return arr;
    }
    public static void printMatrix(int[][] arr) {
        for(int i =0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        return;
    }
    public static int[][] transpose(int[][] arr) {
        int[][] arrt = new int[arr[0].length][arr.length];
        for(int i =0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                arrt[i][j]=arr[j][i];
            }
        }
        return arrt;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] A = new int[rows][cols];
        getMatrix(A);
        printMatrix(transpose(A));
    }
    }
