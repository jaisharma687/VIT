import java.util.*;
public class ReverseString {
    public static void main(String arg[]){
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();
    StringBuilder sb = new StringBuilder("");
    for(int i = str.length()-1;i>=0;i--){
        sb.append(str.charAt(i));
    }
    System.out.println(sb);
}
}
