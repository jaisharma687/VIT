import java.util.*;

public class subarray_pdt {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        int[] prefix = new int[n+1];
        prefix[0] = 1;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] * arr[i - 1];
        }
        int max = 0;
        int window = n;
        while(window>=1){
            for(int i=0;i<=n-window;i++){
                max  = Math.max(max, prefix[i+window]/prefix[i]);
            }
            window--;
        }
        System.out.println(max);
        input.close();
    }
}
