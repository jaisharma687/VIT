import java.util.*;

public class block_swap {
    public static int[] rotateRight(int arr[]){
        int last = arr[arr.length-1];
        for(int i = arr.length-1; i>0;i--){
            arr[i] = arr[i-1];
        }
        arr[0] = last;
        return arr;
    }
    public static int[] rotateLeft(int arr[]){
        int first = arr[0];
        for(int i = 0; i<arr.length-1;i++){
            arr[i] = arr[i+1];
        }
        arr[arr.length-1] = first;
        return arr;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = input.nextInt();
        }
        int l = input.nextInt();
        int r = input.nextInt();
        while(l>0){
            rotateRight(arr);
            l--;
        }
        while(r>0){
            rotateLeft(arr);
            r--;
        }
        for(int i=0;i<n;i++){
            System.out.print(arr[i] + " ");
        }
        input.close();
    }
}
