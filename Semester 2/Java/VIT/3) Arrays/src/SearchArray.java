import java.util.*;
public class SearchArray {
    public static void main(String[] args) throws Exception {
        System.out.println("Enter the size: ");
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] arr = new int[size];
        for(int i = 0; i<size;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Array: ");
        for(int i = 0; i<size;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
        System.out.println("Enter the number to be searched: ");
        int x = sc.nextInt();
        for(int i = 0; i<arr.length;i++){
            if(x==arr[i]){
                System.out.println(i);
            }
        }
    }
}
