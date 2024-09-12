import java.util.Scanner;

public class CompareString {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String st = sc.nextLine();
        String str = "Kohli";
        if(str.equals(st)){
            System.out.println("Matching");
        }
        else{
            System.out.println("Not Matching");
        }
    }
}
