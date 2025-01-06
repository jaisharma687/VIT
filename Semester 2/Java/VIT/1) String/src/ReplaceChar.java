import java.util.*;
public class ReplaceChar {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String or = sc.next();
        String result = "";
        for(int i = 0;i<or.length();i++){
            if(or.charAt(i) == 'e'){
                result+='i';
            }
            else{
                result += or.charAt(i);
            }
        }
        System.out.println(result);
    }
}
