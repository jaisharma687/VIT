class Car{
    void vehicleType(){};
    Car(){};
}
class Maruti extends Car{
    Maruti(){
        System.out.println("Sub Class name");
    }
    void Brand(){
        System.out.println("Maruti");
    }
    void Speed(){
        System.out.println("Speed "+120);
    }
}
class Baleno extends Maruti{
    Baleno(){
        System.out.println("Baleno");
    }
    void Speed(){
        System.out.println("Speed "+120);
    }
}
public class CarProb{
    public static void main (String arg[]){
        Baleno b1=new Baleno();
        b1.vehicleType();
        b1.Brand();
        b1.Speed();
    }
}
