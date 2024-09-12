class ParentClass200{
    public ParentClass200(){
        System.out.println("Parent Class default Constructor");
    }
    public ParentClass200(int x){
        System.out.println("Parent Class default "+ x);
    }
}
public class WithSuper extends ParentClass200{
    public WithSuper(){
        super();
        System.out.println("Child Class default Constructor");
    }
    public static void main(String args[]){
        WithSuper s = new WithSuper();
    }
    }
