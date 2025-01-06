public class StringManu3{
    public static void main(String[] args) {
        String a = "WelComE TO Java";
        String b ="";
        for(int i = 0; i<a.length();i++){
            if(a.charAt(i)>=65 && a.charAt(i)<=90){
                char d = (char) (a.charAt(i)+32);
                b += d;
            }
            else if(a.charAt(i)>=97 && a.charAt(i)<=122){
                char d = (char) (a.charAt(i)-32);
                b += d;
            }
            else{
                char d = a.charAt(i);
                b += d;
            }
        }
        System.out.println(b);
    }
}