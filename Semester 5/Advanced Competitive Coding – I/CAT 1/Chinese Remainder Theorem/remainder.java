import java.util.*;

public class remainder {
    static int ChineseRemainder(int n, int[] remainders, int[] mods){
        int M = 1;
        int[] m = new int[n];
        for(int i=0;i<n;i++) M *= mods[i];
        for(int i=0;i<n;i++) m[i] = M / mods[i];
        int[] ys = new int[n];
        for(int i=0;i<n;i++){
            int y = 0;
            while((m[i]*y)%mods[i] != 1) y++;
            ys[i] = y;
        }
        int x=0;
        for(int i=0;i<n;i++) x+=remainders[i]*m[i]*ys[i];
        return x%M;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of Congurence relations:");
        int n = sc.nextInt();
        int[] remainders = new int[n];
        int[] mods = new int[n];
        System.out.println("Enter the n remainders:");
        for(int i=0;i<n;i++) remainders[i] = sc.nextInt();
        System.out.println("Enter n mods:");
        for(int i=0;i<n;i++) mods[i] = sc.nextInt();
        System.out.println(ChineseRemainder(n, remainders, mods));
        sc.close();
    }
}
