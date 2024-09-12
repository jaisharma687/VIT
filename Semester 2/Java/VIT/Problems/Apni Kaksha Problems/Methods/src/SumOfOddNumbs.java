import java.util.Scanner;

public class SumOfOddNumbs {
    public static void SumOfOdd(int n){
        if(n%2==0){
            int su = 0;
            for(int i = 1; i<n;i=i+2){
                su = su + i;
            }
            System.out.println(su);
            return;
        }
        else{
            int su = 0;
            for(int i = 1; i<=n;i=i+2){
                su = su + i;
            }
            System.out.println(su);
            return;
        }
    }
    public static void main(String arg[]){
        Scanner numb = new Scanner(System.in);
        int a = numb.nextInt();
        SumOfOdd(a);
    }
}
