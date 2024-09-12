import java.util.Scanner;

public class GreatestCommonDivisorOFNumb {
    public static int GreatestCommonDivisor(int a,int b){
        int gcd = 1;
        if(a>b){
            for(int i = 2 ;i<=b;i++){
                if(a%i==0 && b%i==0){
                    gcd = i;
                }
            }
        }
        else{
            for(int i = 2 ;i<=a;i++){
                if(a%i==0 && b%i==0){
                    gcd = i;
                }
            }
        }
        return gcd;
    }
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(GreatestCommonDivisor(a, b));
    }
}
