import java.util.Random;

public class DiceProblem {
    public static void main (String arg[]){
        Random rand = new Random();
        boolean cond = true;
        int count = 1;
        while(cond == true){
            int a = rand.nextInt(7);
            int b = rand.nextInt(7);
        if(a+b==7){
            System.out.println(a+" + "+b+" = "+(a+b));
            cond = false;
        }
        else{
            System.out.println(a+" + "+b+" = "+(a+b));
            cond = true;
            count +=1;
        }}
        System.out.println(count);
    }
    }

