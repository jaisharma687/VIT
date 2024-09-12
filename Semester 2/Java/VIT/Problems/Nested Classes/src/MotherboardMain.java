public class MotherboardMain {
    public static void main(String[] args) {
        // create an object of the static nested class
        // using the name of the outer class
        Motherboard.USB usb = new Motherboard.USB();
        System.out.println("Total Ports = " + usb.getTotalPorts());
    }
 }
 
