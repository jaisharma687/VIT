class A{
    void display100(){
        System.out.println("I am parent class A");
    }
}
interface A1{
    void display100();
}
interface A2{
    void display100();
}
class A11 extends A implements A1{
    public void display100(){
        System.out.println("I am in Child class A11");
    }
}
class A12 extends A implements A1,A2{
    public void display100(){
        System.out.println("I am in Child class A12");
    }
}
public class Inheritance2 {
    public static void main(String[] args) {
        A11 obj = new A11();
        obj.display100();
        // new A12().display100();
        // new A().display();
    }
}
