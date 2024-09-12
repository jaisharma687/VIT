public class T2 {
    void Votingage(int age){ 
        if(age<18) {
        throw new ArithmeticException("you can't vote as not Eligible to vote");} 
        else {
            System.out.println("Eligible for voting");
        } 
    } 
    public static void main(String args[]){ 
        T2 obj = new T2();
        try {
        obj.Votingage(13); }
        catch(ArithmeticException e) {
        System.out.println(e); }
        System.out.println("End Of Program"); 
    }
}
