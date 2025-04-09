import java.util.*;

public class OTP {
    public static String xorOp(String text, String key){
        StringBuilder ss = new StringBuilder();
        for(int i=0;i<text.length();i++){
            ss.append((char)(text.charAt(i)^key.charAt(i)));
        }
        return ss.toString();
    }

    public static String generateKey(int len){
        Random rand = new Random();
        StringBuilder ss = new StringBuilder();
        for(int i=0;i<len;i++){
            ss.append((char)('a'+rand.nextInt(26)));
        }
        return ss.toString();
    }

    public static String toHex(String s){
        StringBuilder hex = new StringBuilder();
        for(int x: s.toCharArray()){
            hex.append(String.format("%02X ", x));
        }
        return hex.toString();
    }

    public static void main(String[] args) {
        String key = generateKey(5);
        String ct = xorOp("hello", key);
        System.out.println(toHex(ct));
        String pt = xorOp(ct, key);
        System.out.println(pt);
    }
}
