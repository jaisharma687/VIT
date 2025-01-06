import java.util.*;

public class longest_palindrome{
    static boolean isPalindrome(String s){
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        int n = input.length();
        int wind = n;
        while(wind>1){
            for(int i=0;i+wind<=n;i++){
                if(isPalindrome(input.substring(i, i+ wind))){
                    System.out.println(input.substring(i, i+ wind));
                    System.exit(0);
                }
            }
            wind--;
        }
        scanner.close();
    }
}