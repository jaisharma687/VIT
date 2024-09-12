import java.util.*;
public class GreaterNumb {
    public static void GreaterNumb(int a, int b){
        if (a>b){
            System.out.println(a);
            return;
        }
        else if(b>a){
            System.out.println(b);
            return;
        }
    }
    public static void main(String[] args){
        Scanner numb = new Scanner(System.in);
        int a = numb.nextInt();
        int b = numb.nextInt();
        GreaterNumb(a,b);
    }
}
