import java.util.Scanner;

public class CountVowelsConst {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int vowel = 0;
        int consonants = 0;
        int etc = 0;
        for(int i = 0;i<str.length();i++){
            if(str.charAt(i)=='A' || str.charAt(i)=='E' ||str.charAt(i)=='I' ||str.charAt(i)=='O' ||str.charAt(i)=='U' ||str.charAt(i)=='a' ||str.charAt(i)=='e' ||str.charAt(i)=='i' ||str.charAt(i)=='o' ||str.charAt(i)=='u'){
                vowel++;
            }
            else if(str.charAt(i)!=' '&&str.charAt(i)!=':'){
                consonants++;
            }
        }
        System.out.println(vowel);
        System.out.println(etc);
        System.out.println(consonants);
    }
}
