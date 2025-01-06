import java.util.*;

public class euclid {
    public static int gcd(int a, int b){
        if(a==0){
            return b;
        }
        return gcd((b%a),a);
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        System.out.println(gcd(a,b));
        input.close();
    }
}
