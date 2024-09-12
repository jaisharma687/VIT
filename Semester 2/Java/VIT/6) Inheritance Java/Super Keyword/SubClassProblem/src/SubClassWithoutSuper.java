//Even when you don’t add super() keyword the compiler will add one and will invoke the Parent Class constructor.
class ParentClass{
public ParentClass(){
    System.out.println("Parent Class default Constructor");
    }
    }
public class SubClassWithoutSuper extends ParentClass{
public SubClassWithoutSuper(){
    System.out.println("Child Class default Constructor");
}
public static void main(String args[]){
    SubClassWithoutSuper s = new SubClassWithoutSuper();
}
}
