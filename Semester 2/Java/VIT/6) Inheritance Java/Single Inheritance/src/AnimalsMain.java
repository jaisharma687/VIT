class Animals{
    void king(){System.out.println("Lion");}
}
class Animals2 extends Animals{
    void nextking(){System.out.println("Tiger");}
}
public class AnimalsMain{
    public static void main (String arg[]){
        Animals2 obj = new Animals2();
        obj.king();
        System.out.println();
        obj.nextking();
    }
}
