import java.util.Scanner;

public class StringManu {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        System.out.println(str1.length());
        System.out.println(str2.length());
        System.out.println(str1.concat(str2));
        System.out.println(str1.toUpperCase());
    }
}
