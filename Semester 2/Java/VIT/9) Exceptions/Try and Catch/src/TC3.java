public class TC3 {
    public static void main(String[] args){
        int x = 0;
        try{
            x = 50/0;
            System.out.println("rest of the code");
        }
        catch(Exception e){
            System.out.println("Catch me if you can: "+e);
        }
        System.out.println(x);
    }
}
