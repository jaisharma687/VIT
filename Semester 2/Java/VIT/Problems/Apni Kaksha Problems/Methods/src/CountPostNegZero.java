import java.util.Scanner;

public class CountPostNegZero {
    public static void main(String arg[]){
        int post=0,neg=0,zer=0;
        Scanner numb = new Scanner(System.in);
        System.out.println("Enter 1 to cont and 0 to end: ");
        int input = numb.nextInt();
        while(input == 1){
            int n = numb.nextInt();
            if(n>0){
                post++;
            }
            else if (n==0){
                zer++;
            }
            else{
                neg++;
            }
            System.out.println("Enter 1 to cont and 0 to end: ");
            input = numb.nextInt();
   
        }
        System.out.println(post);
        System.out.println(zer);
        System.out.println(neg);
    }
}
