import java.util.*;

public class equilibrium_sum {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        int[] prefix = new int[n+1];
        prefix[0] = 0;
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + arr[i-1];
        }
        int max_sum = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int ls = prefix[i+1] - arr[i];
            int rs = prefix[n] - prefix[i+1];
            if(ls==rs){
                max_sum = Math.max(max_sum, ls);
            }
        }
        System.out.println(max_sum);
        input.close();
    }
}
