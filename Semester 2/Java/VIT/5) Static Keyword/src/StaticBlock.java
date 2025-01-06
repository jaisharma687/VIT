public class StaticBlock {
   static int a = 23;
   static int b;
   static int max;
   static {
        System.out.println("First Static block.");
        b = a * 4;
    }
   static {
        System.out.println("Second Static block.");
        max = 30;  
    }
    static void display() {
        System.out.println("a = " + a);
        System.out.println("b = " + b);
        System.out.println("max = " + max);
   }
    public static void main(String args[]) {
        display();
   }
}
