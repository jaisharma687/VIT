import java.io.IOException;
public class TS2 {
    void first() throws IOException {  
        throw new IOException("error");  
       }  
       void second() throws IOException {  
        first();  
       }  
       void third(){  
        try {  
         second();  
        } 
        catch (IOException e) {  
            System.out.println("work is done "+e);  
        }  
       }  
       public static void main(String[] args) {  
       TS2 obj = new TS2(); 
       obj.third();
       System.out.println("all in control");  
       }  
       
      
}
