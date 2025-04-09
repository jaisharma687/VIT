import java.util.*;

public class RC4 {
    static int n = 3;
    static String plainText = "001010010010", key = "101001000001";
    static List<Integer> S = new ArrayList<>(), 
    keyList = new ArrayList<>(), 
    keyStream = new ArrayList<>(), 
    cipherText = new ArrayList<>();
    
    public static void main(String[] args) {
        encrypt();
        decrypt();
    }

    static void encrypt() {
        System.out.printf("Plain text: %s\nKey: %s\nn: %d\n", plainText, key, n);
        initializeS();
        processKey();
        KSA();
        generateKeystream(convertToDecimal(plainText).size());
        cipherText = xor(convertToDecimal(plainText), keyStream);
        System.out.println("Cipher text: " + toBinaryString(cipherText));
    }

    static void decrypt() {
        S.clear(); keyList.clear(); keyStream.clear();
        initializeS();
        processKey();
        KSA();
        generateKeystream(cipherText.size());
        List<Integer> decrypted = xor(cipherText, keyStream);
        System.out.println("Decrypted text: " + toBinaryString(decrypted));
    }

    static void initializeS() {
        for(int i = 0; i < Math.pow(2, n); i++) S.add(i);
        System.out.println("Initial S: " + S);
    }

    static void processKey() {
        keyList = convertToDecimal(key);
        int diff = S.size() - keyList.size();
        for(int i = 0; diff > 0 && i < diff; i++) 
            keyList.add(keyList.get(i % keyList.size()));
        System.out.println("Processed key: " + keyList);
    }

    static void KSA() {
        for(int i = 0, j = 0; i < S.size(); i++) {
            j = (j + S.get(i) + keyList.get(i)) % S.size();
            Collections.swap(S, i, j);
        }
        System.out.println("Permuted S: " + S);
    }

    static void generateKeystream(int length) {
        for(int i = 0, j = 0, k = 0; k < length; k++) {
            i = (i + 1) % S.size();
            j = (j + S.get(i)) % S.size();
            Collections.swap(S, i, j);
            keyStream.add(S.get((S.get(i) + S.get(j)) % S.size()));
        }
        System.out.println("Keystream: " + keyStream);
    }

    static List<Integer> xor(List<Integer> a, List<Integer> b) {
        List<Integer> result = new ArrayList<>();
        for(int i = 0; i < a.size(); i++) result.add(a.get(i) ^ b.get(i));
        return result;
    }

    static List<Integer> convertToDecimal(String input) {
        List<Integer> result = new ArrayList<>();
        for(int i = 0; i < input.length(); i += n)
            result.add(Integer.parseInt(input.substring(i, Math.min(input.length(), i + n)), 2));
        return result;
    }

    static String toBinaryString(List<Integer> list) {
        StringBuilder sb = new StringBuilder();
        for(int num : list) sb.append(String.format("%0" + n + "d", Integer.parseInt(Integer.toBinaryString(num))));
        return sb.toString();
    }
}
