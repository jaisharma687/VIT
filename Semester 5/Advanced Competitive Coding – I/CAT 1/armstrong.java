import java.util.*;

public class armstrong {
    static boolean isArmstrong(int n){
        int p = n;
        int res = 0;
        while(n>0){
            int num = n %10;
            n/=10;
            res += Math.pow(num,3);
        }
        return p==res;
    }
    public static void main(String[] args){
        Scanner sc  = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(isArmstrong(n));
        sc.close();
    }
}
