import java.util.*;
public class CumulativeLength {
    public static void main(String arg[]){
    Scanner sc = new Scanner(System.in);
    int inputs = sc.nextInt();
    int len = 0;
    for(int i = 0;i<=inputs;i++){
        String str = sc.nextLine();
        len = len + str.length();
    }
    System.out.println(len);
}}