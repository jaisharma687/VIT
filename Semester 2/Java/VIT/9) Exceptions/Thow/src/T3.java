public class T3 {
    //we use static keyword here because in that case we do not have to intialize an object to call it
    static void method1(){
        System.out.println("Inside the method1:");
        try{
            method2();
        }
        catch(Exception e){
            System.out.println("The Exception is: "+e);
        }
        System.out.println("After Method 2");
    }
    static void method2(){
        throw new ArithmeticException(" Testing Throw");
    }
    public static void main(String args[]){
        method1();
    }
}