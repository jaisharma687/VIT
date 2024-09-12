import java.util.Scanner;
public class StringManu {
    public static void main(String[] args) {
        String a,b;
        Scanner obj = new Scanner(System.in);
        a = obj.nextLine();
        b = obj.nextLine();
        System.out.println(a.length()+" "+b.length());
        System.out.println(a + " " +b);
        System.out.println(a.toUpperCase());
    }
}
