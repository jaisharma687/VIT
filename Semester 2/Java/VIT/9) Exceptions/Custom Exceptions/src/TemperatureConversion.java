import java.util.*;
class InputMismatchException extends Exception{
    InputMismatchException(String s){
        super(s);
    }
}
class Temperature{
    double getFahren(double cel) throws InputMismatchException{
        double fahrenheit;
        return fahrenheit = ((9.0 * cel)/5.0)+ 32.0;
    }
    double getCel(double fahren) throws InputMismatchException{
        double celsius;
        return celsius = (fahren - 32.0)*5.0/9.0;
    }
}
public class TemperatureConversion{
    public static void main(String[] args) {
        Temperature obj = new Temperature();
        Scanner p = new Scanner(System.in);
        double f = p.nextDouble();
        double c = p.nextDouble();
        try {
            if(c == (int)c & f == (int)f){
                System.out.println(obj.getFahren(c));
                System.out.println(obj.getCel(f));
            }
            else{
                throw new InputMismatchException("Enter correct input");
            }
        } catch (InputMismatchException e) {
            System.out.println("Kya hua: " + e);
        }
            

    }
}