class Flowers
{ 
    public void colours() 
    { 
       System.out.println("Different"); 
    } 
} 
class Roses extends Flowers
{ 
    public void colours1() 
    { 
        System.out.println("Red"); 
    } 
}  
class Lotus extends Flowers
{ 
    public void colours3() 
    { 
        System.out.println("White"); 
    } 
} 
public class FlowersMain2 {
    public static void main(String arg[]){
        Lotus g = new Lotus(); 
        g.colours(); 
        g.colours3();
        Roses t = new Roses(); 
        t.colours(); 
        t.colours1(); 
    }
}
