//Jai Sharma
//22BEE0191
public class PAT31Main {
    public static void main(String arg[]){
        PAT31 ckt = new PAT31(1, -1, 15, 91, -2, 10);
        ckt.getA();
        ckt.getB();
        ckt.getC();
        ckt.getD();
        ckt.getE();
        ckt.getF();
        ckt.isSolvable();
        if(ckt.isSolvable()!=0){
        System.out.println(ckt.getX());
        System.out.println(ckt.getY());
        }
        else{
            System.out.println("The equation has no solution");
        }
    }
}