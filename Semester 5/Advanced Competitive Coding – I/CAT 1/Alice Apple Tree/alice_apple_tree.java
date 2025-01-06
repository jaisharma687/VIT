import java.util.*;

public class alice_apple_tree {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int apple = sc.nextInt();
        int count = 0;
        int sum = 0;
        while(sum<apple){
            count++;
            sum+=12*count*count;
        }
        System.out.println(sum);
        sc.close();
    }
}
