import java.util.*;

public class sorting {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = input.length;
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(arr);
        for(int x: arr){
            System.out.println(x);
        }
        scanner.close();
    }
}
