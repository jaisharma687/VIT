import java.util.*;

public class palindrome {
    // static boolean isPalindrome(String n){
    //     int l = 0;
    //     int r = n.length()-1;
    //     while(l<=r){
    //         if(n.charAt(l) != n.charAt(r)) return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    static boolean isPalindrome(int n){
        int p =n;
        int res = 0;
        while(n>0){
            res = res *10 + n%10;
            n/=10;
        }
        return p==res;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // String n = sc.nextLine();
        int n = sc.nextInt();
        System.out.println(isPalindrome(n));
        sc.close();
    }
}
