class StaticBlocks {
    // static variables
    static int a = 23;
    static int b;
    static int max;
    // static blocks
    static {
        System.out.println("Second Static block.");
        max = 30;  
    }
    static {
        System.out.println("First Static block.");
        b = a * 4;
        System.out.println(b);
    }
    static void display() { // // static method
        System.out.println("a = " + a);
        System.out.println("b = " + b);
        System.out.println("max = " + max);
    }
    public static void main(String args[]) {
        // calling the static method
        display();
    }
}
 