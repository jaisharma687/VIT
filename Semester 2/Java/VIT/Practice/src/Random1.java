import java.util.Random;

public class Random1 {
    public static void main(String[] args) {
        Random ran = new Random();
        int count = 1;
        boolean cont = true;
        while(cont == true){
            int a = ran.nextInt(6)+1;
            int b = ran.nextInt(6)+1;
            if((a+b) != 7){
                System.out.println(a+" + "+b+" = "+(a+b));
                count++;
            }
            else{
                System.out.println(a+" + "+b+" = "+(a+b));
                System.out.println("You won after "+ count+" tries!!!");
                cont = false;
            }
        }
    }
}
