import java.util.*;

public class Caesar {
    public static String encrypt(String p, int key){
        StringBuilder ss = new StringBuilder();
        for(int i=0;i<p.length();i++){
            ss.append((char)((((p.charAt(i)-'a')+key)%26)+'a'));
        }
        return ss.toString();
    }

    public static void decrypt(String c){
        for(int key=1;key<26;key++){
            StringBuilder ss = new StringBuilder();
            for(int i=0;i<c.length();i++){
                ss.append((char)((((c.charAt(i)-'a')-key+26)%26)+'a'));
            }
            System.out.println("Decrypted Text for key "+key+" is "+ ss.toString());
        }
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String pt = sc.nextLine();
        int key = sc.nextInt();
        System.out.println("Encrypted Text: "+encrypt(pt, key));
        decrypt(encrypt(pt, key));
    }
}
