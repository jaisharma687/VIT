import java.util.*;

public class CoinTossProblem {
    public static void main(String arg[]){
        Random rand = new Random();
        int heads = 0;
        int tails = 0;
        int i = 0;
        while(i<100){
            boolean coinflip = rand.nextBoolean();
            if(coinflip == true){
                System.out.println("Heads");
                heads++;
                i++;
            }
            else{
                System.out.println("Tails");
                tails++;
                i++;
            }
        }
        System.out.println("Heads: "+ heads);
        System.out.println("Tails: "+ tails);
    }
}
