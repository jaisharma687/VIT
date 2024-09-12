//JAI SHARMA
//22BEE0191
import java.util.*;
public class PAT22 {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int b = 0;
        char string[]=str.toCharArray();
        // for (int i= 0; i< str.length(); i++) {
        //     int count = 0;
        //     for (int j= 0; j< str.length(); j++) {
        //         if(string[i]==string[j] && string[i]!=' '){
        //             count++;
        //         }
        //     }
        //     if(count>1){
        //         System.out.println(string[i] + " = " + count);}}}}
        for(int i=0;i<str.length();i++){
            b=1;
            for(int j=i+1;j<str.length();j++){
                if(string[i]==string[j] && string[i]!=' '){
                    b++;
                    string[j]='0';
                }
            }
            if(b>1&&string[i]!='0'){
                System.out.println(string[i]+ " = "+b);
            }
        }
    }}