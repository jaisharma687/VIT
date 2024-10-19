import java.util.*;

public class leaders {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        ArrayList<Integer> leaders = new ArrayList<>();
        int mx = arr[n-1];
        leaders.add(mx);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>mx){
                mx = arr[i];
                leaders.add(mx);
            }
        }
        for(int x: leaders){
            System.out.print(x+" ");
        }
        input.close();
    }
}
