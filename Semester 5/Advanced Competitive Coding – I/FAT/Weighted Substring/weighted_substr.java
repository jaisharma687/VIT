import java.util.*;

public class weighted_substr {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int weight = scanner.nextInt();
        scanner.close();
        List<Integer> weights = new ArrayList<Integer>();
        int curr = 1;
        int i=2;
        while(curr<=weight){
            weights.add(curr);
            curr = i*curr + curr;
            i++;
        }
        int n = weights.size();
        String out = "";
        for(i=n-1;i>=0;i--){
            int w = weights.get(i);
            char x = (char)(i+'A');
            while(weight-w>=0){
                weight-=w;
                out = x + out;
            }
        }
        System.out.println(out);
    }
}
