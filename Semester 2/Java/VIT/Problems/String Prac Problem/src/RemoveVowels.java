import java.util.Scanner;

public class RemoveVowels {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String st = "";
        for(int i = 0;i<str.length();i++){
            if(str.charAt(i)=='A' | str.charAt(i)=='E' |str.charAt(i)=='I' |str.charAt(i)=='O' |str.charAt(i)=='U' |str.charAt(i)=='a' |str.charAt(i)=='e' |str.charAt(i)=='i' |str.charAt(i)=='o' |str.charAt(i)=='u'){
                continue;}
           else{st += str.charAt(i);}
        }
        System.out.println(st);
}}