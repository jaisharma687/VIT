import java.util.*;

public class Multiplicative {
    public static String encrypt(String p, int key){
        StringBuilder ss = new StringBuilder();
        for(char x: p.toCharArray()){
            ss.append((char)((((x-'a')*key)%26)+'a'));
        }
        return ss.toString();
    }
    public static int modInverse(int key, int mod){
        for(int i=1;i<mod;i++){
            if((key*i)%mod==1){
                return i;
            }
        }
        return -1;
    }
    public static void decrypt(String c){
        for(int key = 1;key<26;key++){
            int inv = modInverse(key, 26);
            if(inv!=-1){
                StringBuilder ss = new StringBuilder();
                for(char x: c.toCharArray()){
                    ss.append((char)((((x-'a')*inv + 26)%26)+'a'));
                }
                System.out.println("Decrypted Text for key "+key+" is "+ss.toString());
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String pt = sc.nextLine();
        int key = sc.nextInt();
        System.out.println("Encrypted Text: "+encrypt(pt, key));
        decrypt(encrypt(pt, key));
    }
}
