import java.util.*;

public class Monoalphabetic {
    private static final String ENGLISH_FREQ = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    public static Map<Character,Integer> freqency(String text){
        Map<Character,Integer> f = new HashMap<>();
        for(char x: text.toUpperCase().toCharArray()){
            f.put(x, f.getOrDefault(x, 0)+1);
        }
        return f;
    }

    public static Map<Character,Character> createMap(Map<Character,Integer> f){
        List<Character> l = new ArrayList<>(f.keySet());
        l.sort((a,b)->f.get(b)-f.get(a));
        Map<Character,Character> mp = new HashMap<>();
        for(int i=0;i<l.size();i++){
            mp.put(l.get(i), ENGLISH_FREQ.charAt(i));
        }
        return mp;
    }

    public static String decrypt(String cipher, Map<Character,Character> mp){
        StringBuilder ss = new StringBuilder();
        for(char x: cipher.toCharArray()){
            ss.append(mp.get(x));
        }
        return ss.toString();
    }
    public static void main(String[] args) {
        System.out.println(decrypt("ONHOVEJHWOBEVGWOCBWHNUGBLHGBGR", createMap(freqency("ONHOVEJHWOBEVGWOCBWHNUGBLHGBGR"))));
    }
}
