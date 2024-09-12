import java.util.*;
public class MaxMinArray {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] arr = new int[size];
        for(int i=0; i<size;i++){
            arr[i] = sc.nextInt();
        }
        int max = 0;
        for(int j=0; j<arr.length;j++){
            if(arr[j]>max){
                max = arr[j]; 
            }
        }
        System.out.println(max);
        int min = arr[1];
        for(int j=0; j<arr.length;j++){
            if(arr[j]<min){
                min = arr[j]; 
            }
        }
        System.out.println(min);
    }
}
