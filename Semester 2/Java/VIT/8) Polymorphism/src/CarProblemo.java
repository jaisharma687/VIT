class Car3000
{ 
    void run4000() 
    { 
        System.out.println("running"); 
    } 
}
class innova extends Car3000 
{ 
    void run4000()
    { 
        System.out.println("running fast at 120km"); 
    } 
    public static void main(String args[]) 
    { 
        Car3000 c = new innova(); 
        c.run4000(); 
    } 
} 

