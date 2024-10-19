import java.util.*;

public class lexicogaphically {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        int n = str.length();
        int[] count = new int[26];
        for(char x: str.toCharArray()){
            int idx = (int)(x - 'a');
            count[idx] ++;
        }
        int count_odd = 0;
        for(int i = 0; i < 26; i++){
            if(count[i]%2!=0) count_odd++;
        }
        if((n%2 == 1 && count_odd != 1) || (n%2 == 0 && count_odd != 0)){
            System.out.println("No Palindromic String");
            System.exit(0);
        }
        String front = "";
        String back = "";
        String odd = "";
        for(int i=0;i<26;i++){
            if(count[i]%2!=0) {
                odd += (char)(i + 'a');
                count[i]--;
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(count[i] != 0){
                int num = count[i];
                String temp = String.valueOf((char)(i+'a')).repeat(num/2);
                front += temp;
                back = temp + back;
            }
        }
        System.out.println(front + odd + back);
        input.close();
    }
}