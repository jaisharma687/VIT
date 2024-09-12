class CPU {
    static int multiply1(int a,int b){
        return a*b;
    }
    class Processor{ 
        double getCache(){
            return 4.3;
        }    
    }
    class RAM{
        int add1(int a,int b){
            return a+b;
        }
        double getClockSpeed(){
            return 5.5;
        }    
    }
}
public class NestedInnerClass {
    public static void main(String[] args) {
        CPU cpu = new CPU();
        CPU.Processor processor = cpu.new Processor();
        CPU.RAM ram = cpu.new RAM();
        System.out.println("Processor Cache = " + processor.getCache());
        System.out.println("Ram Clock speed = " + ram.getClockSpeed());
        System.out.println(ram.add1(2,5));
        System.out.println(CPU.multiply1(2,5));
    }
}
