import java.util.Scanner;

public class CreateUserName {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int index = 0;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='@'){
                index += i;
            }
        }
        System.out.println(str.substring(0, index));
    }
}
