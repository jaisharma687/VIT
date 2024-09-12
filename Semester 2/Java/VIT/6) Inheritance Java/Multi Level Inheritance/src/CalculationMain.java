class Calculation 
{
   int z;
   public void addition(int x, int y) 
   {
      z = x + y;
      System.out.println(z);
   }
   public void subtraction(int x, int y)
   {
      z = x - y;
      System.out.println(z);
   }
}
class Calculate extends Calculation {
   public void multiplication(int x, int y)
   {
      z = x * y;
      System.out.println(z);
   }
}
public class CalculationMain {
    public static void main(String arg[]){
    int x = 10, y = 20;
    Calculate obj = new Calculate();
    obj.addition(x, y);
    obj.subtraction(x, y);
    obj.multiplication(x, y);
    }
}
