public class StringManu5 {
    public static void main(String[] args) {
        int n = 12321;
        int k = n;
        int m = 0;
        while(n>0){
            int rem = n%10;
            n = n/10;
            m = m*10 + rem;
        }
        if(k == m){
            System.out.println("Hehe");
        }
    }
}
