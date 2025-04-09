import java.util.*;

public class Vigenere {
    public static String encrypt(String pt, String key){
        StringBuilder ss = new StringBuilder();
        key = key.toLowerCase();
        pt = pt.toLowerCase();
        for(int i=0;i<pt.length();i++){
            char y = (char)((((int)(pt.charAt(i)-'a') + (int)(key.charAt(i % key.length())-'a') + 26) % 26) + 'a');
            ss.append(y);
        }
        return ss.toString();
    }
    public static String decrypt(String pt, String key){
        StringBuilder ss = new StringBuilder();
        key = key.toLowerCase();
        pt = pt.toLowerCase();
        for(int i=0;i<pt.length();i++){
            char y = (char)((((int)(pt.charAt(i)-'a') - (int)(key.charAt(i % key.length())-'a') + 26) % 26) + 'a');
            ss.append(y);
        }
        return ss.toString();
    }
    public static void main(String[] args) {
        String ct = encrypt("hello", "vit");
        String pt = decrypt(ct, "vit");
        System.out.println(ct);
        System.out.println(pt);
    }
}
