
public class StringManu2 {
    public static void main(String[] args) {
        int a = 762351;
        int b = 1;
        while(a>0){
            int rem = (a%100)/10;
            System.out.print(rem+" ");
            b = b*rem;
            a = a/100;
        }
        System.out.println(b);
    }
}
