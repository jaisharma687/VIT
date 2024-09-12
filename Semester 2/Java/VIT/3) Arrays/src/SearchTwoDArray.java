import java.util.*;
public class SearchTwoDArray {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] arr = new int[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter the number to be searched: ");
        int x = sc.nextInt();
        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(arr[i][j]==x){
                    System.out.println(i + " " + j);
                }
            }
        }
    }
}
