import java.util.*;

public class binary_palindrome {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        String num = Integer.toBinaryString(number);
        int n = num.length();
        int left = 0;
        int right = n-1;
        boolean flag = true;
        while(left < right) {
            if(num.charAt(left) != num.charAt(right)){
                flag = false;
                break;
            }
            left++;
            right--;
        }
        System.out.println(flag);
        input.close();
    }
}