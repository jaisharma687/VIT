class ClassA 
{
    public void dispA(){
        System.out.println("Program");
    }
}
interface InterfaceB
{
    public void show();
}
interface InterfaceC 
{
    public void show();
}
public class ClassD extends ClassA implements InterfaceB,InterfaceC{
    public void show()
    {
        System.out.println("Cracker");
    } 
    public void dispD(){
        System.out.println("Coding");
    }
    public static void main(String args[]){
        ClassD d = new ClassD();
        d.dispD();
        d.show();
        d.dispA();
    }
}