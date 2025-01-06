import java.util.Scanner;

public class StringManupl {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int upper = 0;
        int lower = 0;
        int digit = 0;
        int special = 0;
        for(int i =0; i<str.length();i++){
            if(str.charAt(i)>='A' && str.charAt(i)<='Z'){
                upper++;
            }
            else if(str.charAt(i)>='a' && str.charAt(i)<='z'){
                lower++;
            }
            else if(str.charAt(i)>= '0'  && str.charAt(i)<= '9'){
                digit++;
            }
            else{
                special++;
            }
            
        }
        System.out.println(upper);
        System.out.println(digit);
        System.out.println(lower);
        System.out.println(special);
    }
}
