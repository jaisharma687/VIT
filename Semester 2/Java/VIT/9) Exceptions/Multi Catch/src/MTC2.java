public class MTC2 {
    public static void main(String[] args) {  
        try{    
             String s=null;  
             System.out.println(s.length());  
            }    
            catch(ArithmeticException e)  
               {  
                System.out.println("Arithmetic Exception occurs");  
               }    
            catch(ArrayIndexOutOfBoundsException e)  
               {  
                System.out.println("ArrayIndexOutOfBounds Exception occurs");  
               } 
            catch(NullPointerException e)  
            {
                System.out.println("NullPointer Exception occurs");
            } 
            catch(Exception e)  
               {  
                System.out.println("Parent Exception occurs");  
               }             
            System.out.println("rest of the code");    
 }  
}
