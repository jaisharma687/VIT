public class StringManu4 {
    public static void main(String[] args) {
        String a = "S.T.D code of New Delhi - 011";
        int upp = 0;
        int low = 0;
        int spe = 0;
        int dig = 0;
        for(int i = 0; i<a.length();i++){
            if(a.charAt(i)>=65 && a.charAt(i)<=90){
                upp++;
            }
            else if(a.charAt(i)>=97 && a.charAt(i)<=122){
                low++;
            }
            else if(a.charAt(i)>=48 && a.charAt(i)<=57){
                dig++;
            }
            else{
                spe++;
            }
        }
        System.out.println(upp);
        System.out.println(low);
        System.out.println(spe);
        System.out.println(dig);
    }
}
