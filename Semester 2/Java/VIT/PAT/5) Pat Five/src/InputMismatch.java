public class InputMismatch {
    public static void main(String[] args) {
        try{
            int x = 5;
            if(x == (int)x){
                throw new InputMismatchException("Invalid input");
            }
        }
        catch(InputMismatchException e){
            System.out.println("Exception is: "+ e);
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
