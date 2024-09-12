final class Bike1
{   
}  
class Honda1 extends Bike1//Throws error as when we use final keyword we cannot inherit a class
{  
    void run1()
    {
         System.out.println("running safely with 100kmph");
    } 
    public static void main(String args[])
    {  
         Honda1 honda= new Honda1();  
       	  honda.run1();  
    }  
} 

   
