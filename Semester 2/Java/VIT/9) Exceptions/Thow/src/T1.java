public class T1 {
    static void validateMarks(int marks) {
        if (marks <80){
        throw new ArithmeticException("Not Oracle certified");}
        else{
        System.out.println("Oracle certified ");}
        }
    public static void main(String args[])
    {
        try {
            validateMarks (2);
        }
        catch(Exception e){
            System.out.println(e); 
        }
        finally{System.out.println("Hello");}
        System.out.println("welcome ...");
    }

}
