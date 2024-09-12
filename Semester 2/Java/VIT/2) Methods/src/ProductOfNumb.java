import java.util.*;
public class ProductOfNumb {
    public static void ProductOfNumber(int a, int b){
        int c = a*b;
        System.out.println(c);
    }
    public static void main(String arg[]){
        Scanner numb = new Scanner(System.in);
        int d = numb.nextInt();
        int e = numb.nextInt();
        ProductOfNumber(d, e);
    }
}
