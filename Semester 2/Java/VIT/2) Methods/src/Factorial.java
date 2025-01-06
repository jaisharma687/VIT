import java.util.*;
public class Factorial {
    public static void FactorialOfNumber(int a){
        int b = 1;
        for(int i = a ; i > 0 ; i--){
            b = b*i;
        }
        System.out.println(b);
        return;
    }
    public static void main(String arg[]){
        Scanner numb = new Scanner(System.in);
        int c = numb.nextInt();
        FactorialOfNumber(c);
    }
}
