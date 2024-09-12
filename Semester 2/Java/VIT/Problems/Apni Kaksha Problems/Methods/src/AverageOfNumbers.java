import java.util.*;
public class AverageOfNumbers {
    public static int Aver(int a, int b , int c){
        int av = (a+b+c)/3;
        //System.out.println(av);
        return av;
    }
    public static void main(String[] args){
        Scanner numb = new Scanner(System.in);
        int a = numb.nextInt();
        int b = numb.nextInt();
        int c = numb.nextInt();
        System.out.println(Aver(a,b,c));
    }
}
