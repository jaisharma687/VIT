class NumberisGreaterThan extends Exception{
    NumberisGreaterThan(){
        System.out.println("Exception ");
        
    }
    
}
public class CE1 {
    public static void main(String[] args){
        try{
            int m = 1502;
            if(m>100){
                throw new NumberisGreaterThan();
            }
        }
        catch(NumberisGreaterThan e){
            System.out.print(e);
        }
        System.out.println(" After try, and catch ");
    }
}
