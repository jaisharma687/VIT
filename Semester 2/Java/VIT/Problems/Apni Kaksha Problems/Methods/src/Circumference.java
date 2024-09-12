import java.util.Scanner;

public class Circumference {
    public static void circum(int r){
        System.out.println(3.14*r*2);
        return;
    }
    public static void main(String arg[]){
        Scanner rad = new Scanner(System.in);
        int r = rad.nextInt();
        circum(r);
    }
}
