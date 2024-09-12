public class TC2 {
    public static void main(String[] args){
        int x = 0;
        try{
            x = 50/0;
            System.out.println("rest of the code");
        }
        catch(Exception e){
            System.out.println(e);
        }
        System.out.println(x);
    }
}