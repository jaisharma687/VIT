import java.util.*;

public class FrequencyAnalysisCipher {
    private static String eng_freq = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    public static String decrypt(String ct){
        int[] freq = new int[26];
        for(char x: ct.toCharArray()){
            int idx = (int)(x-'A');
            freq[idx]++;
        }
        Map<Character,Character> charSwap = new HashMap<>();
        int j = 0;
        for(int i=0;i<26;i++){
            int mx = -1;
            int mxIdx = -1;
            for(int k=0;k<26;k++){
                if(mx<freq[k]){
                    mx = freq[k];
                    mxIdx = k;
                }
            }
            if(mxIdx!=-1){
                freq[mxIdx] = -1;
            }
            if(mxIdx==-1){
                break;
            }
            charSwap.put((char)(mxIdx+'A'), eng_freq.charAt(j++));
        }
        StringBuilder res = new StringBuilder();
        for(char x: ct.toCharArray()){
            res.append(charSwap.getOrDefault(x,x));
        }
        return res.toString();
    }

    public static void main(String[] args){
        String ct = "ONHOVEJHWOBEVGWOCBWHNUGBLHGBGR";
        System.out.println(decrypt(ct));
    }
}
