public class NullPointExcep {
    public static void main(String[] args) {
        try{
            String str = null;
            System.out.println(str.length());
        }
        catch(ArithmeticException e){
            System.out.println(e);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }
        catch(NullPointerException e){
            System.out.println(e);
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
