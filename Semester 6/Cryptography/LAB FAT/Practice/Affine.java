import java.util.*;
public class Affine {
    public static int modInverse(int key, int mod){
        for(int i=1;i<mod;i++){
            if((key*i)%mod==1){
                return i;
            }
        }
        return -1;
    }
    public static String encrypt(String p, int k1, int k2){
        StringBuilder ss = new StringBuilder();
        for(char x: p.toCharArray()){
            int ascii = x - 'a';
            int asciiMult = ascii * k1;
            int asciiCaesar = asciiMult + k2;
            char newChar = (char)((asciiCaesar%26)+'a');
            ss.append(newChar); 
        }
        return ss.toString();
    }
    public static void decrypt(String p){
        for(int k2=1;k2<26;k2++){
            for(int k1=1;k1<26;k1++){
                int inv = modInverse(k1, 26);
                if(inv!=-1){
                    StringBuilder ss = new StringBuilder();
                    for(char x: p.toCharArray()){
                        int ascii = x - 'a';
                        int asciiCaesar = ascii - k2 + 26;
                        int asciiMult = asciiCaesar * inv;
                        char newChar = (char)((asciiMult%26)+'a');
                        ss.append(newChar); 
                    }
                    System.out.println("Key1: "+k1+" Key2: "+k2+" CT: "+ss.toString());
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k1 = 5;
        int k2 = 14;
        String p = "hello";
        System.out.println(encrypt(p, k1, k2));
        decrypt(encrypt(p, k1, k2));
    }
}
