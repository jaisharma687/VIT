import java.util.Scanner;

public class AgeOfVoter{
    public static void Age(int a){
        if(a>=18){
            System.out.println("Elligible");
        }
        else{
            System.out.println("Not Elligible");
        }
        }

    public static void main(String arg[]){
        Scanner ag = new Scanner(System.in);
        int a = ag.nextInt();
        Age(a);
    }
}