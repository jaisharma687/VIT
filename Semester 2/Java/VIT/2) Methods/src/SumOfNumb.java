import java.util.*;
public class SumOfNumb {
    public static void SumOfNumber(int a, int b){
        int c = a+b;
        System.out.println(c);
    }
    public static void main(String arg[]){
        Scanner numb = new Scanner(System.in);
        int d = numb.nextInt();
        int e = numb.nextInt();
        SumOfNumber(d, e);
    }
}
