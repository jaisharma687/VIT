class A{
    void display(){
        System.out.println("Hello World");
    }
}
class B extends A{
    void display(int x){
        System.out.println(x);
    }
}
class C extends A{
    void display(String s){
        System.out.println(s);
    }
}
public class Q2 {
    public static void main(String[] args) throws Exception {
        new A().display();
        new B().display();
        new B().display(40);
        new C().display("Hello");
    }
}
