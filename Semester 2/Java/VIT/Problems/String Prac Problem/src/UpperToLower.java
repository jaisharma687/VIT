import java.util.Scanner;
import java.lang.*;
public class UpperToLower {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String str2 = "";
        for(int i = 0; i<str.length();i++){
            if(str.charAt(i)>='A' && str.charAt(i)<='Z'){
                str2 += Character.toLowerCase(str.charAt(i));
            }
            else if(str.charAt(i)>='a'&&str.charAt(i)<='z'){
                str2 += Character.toUpperCase(str.charAt(i));
            }
            else{
                str2 += str.charAt(i);
            }
        }
        System.out.println(str2);
    }
}
