class A{
    void m(){System.out.println("Hello World");}
    void n(){
        System.out.println("hello world");
        this.m();
    }
}
class ThisForMethods {
    public static void main(String arg[]){
        A obj = new A();
        obj.m();
        System.out.println(" ");
        obj.n();
    }
}
