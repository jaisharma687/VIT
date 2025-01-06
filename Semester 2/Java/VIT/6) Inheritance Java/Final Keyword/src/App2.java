class Bike2
{  
  final void run2()
  {
      System.out.println("running");} }  
class Honda2 extends Bike2
{  
    void run2()
    {
       System.out.println("running safely with 100kmph");
    }   
    public static void main(String args[])
    {    
        Honda2 honda= new Honda2();  
        honda.run2();  
    }  
} 
