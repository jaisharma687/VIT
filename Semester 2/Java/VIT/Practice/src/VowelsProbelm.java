public class VowelsProbelm {
    public static void main(String[] args) {
        String a = "Computer Programming: JAVA";
        int vowels = 0;
        int cons = 0;
        for(int i =0;i<a.length();i++){
            if(a.charAt(i)=='a'|| a.charAt(i)=='e'|| a.charAt(i)=='i'|| a.charAt(i)=='o'|| a.charAt(i)=='u'
            || a.charAt(i)=='A'|| a.charAt(i)=='E'|| a.charAt(i)=='I'|| a.charAt(i)=='O'|| a.charAt(i)=='U'){
                vowels ++;
            }
            else if((a.charAt(i)>=65 && a.charAt(i)<=90 )|| (a.charAt(i)>=97 && a.charAt(i)<122)){
                cons ++;
            }
        }
        System.out.println(vowels);
        System.out.println(cons);
    }
}
