import java.util.Random;
public class RandomTest {
    public static void main(String[] args){
        Random ran = new Random();
        int randNum = ran.nextInt();
        System.out.println(randNum);
        int randNum1 = ran.nextInt(10);
        System.out.println(randNum1);
        double randNum2 = ran.nextDouble();
        System.out.println(randNum2);
        Boolean randBoo = ran.nextBoolean();
        System.out.println(randBoo);
        int randNum3 = ran.nextInt(10) + 55;
        //To get a number in arbitrary range [min, max] inclusive: 
        //nextInt(size of range) + min        
        System.out.println(randNum3);
    }
}
