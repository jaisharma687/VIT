import java.util.*;

public class longest_sequence {
    public static void main(String arg[]){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String bin = Integer.toBinaryString(n);
        int mx = 0;
        int res = 0;
        for(char x: bin.toCharArray()){
            if(x == '1'){
                mx++;
                res = Math.max(mx,res);
            }
            else{
                res = Math.max(mx,res);
                mx = 0;
            }
        }
        System.out.println(res);
        input.close();
    }
}
