public class Q3 {
    public static void main(String[] args) {
        int x = 50;
        try{
            int y = x/0;
        }
        catch(ArithmeticException e){
            System.out.println(e);
            System.out.println("Exception Handled.");
        }
        catch(NullPointerException e){
            System.out.println(e);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}