import java.util.*;
public class ArraySortCheck {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] arr = new int[size];
        for(int i=0; i<size;i++){
            arr[i] = sc.nextInt();
        }
        int count = 0;
        int max = 0;
        for(int j=0; j<arr.length;j++){
            if(arr[j]>max){
                max = arr[j];
                count++;
            }
        }
        
        if(count==arr.length){
            System.out.println("Sorted");
        }
        else{
            System.out.println("Not Sorted");
        }
    }
}
