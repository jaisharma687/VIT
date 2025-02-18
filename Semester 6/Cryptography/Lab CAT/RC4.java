import java.util.*;

public class RC4 {
    static int n = 3;
    static String plain_text = "001010010010";
    static String key = "101001000001";
    static List<Integer> S = new ArrayList<>();
    static List<Integer> key_list = new ArrayList<>();
    static List<Integer> pt = new ArrayList<>();
    static List<Integer> key_stream = new ArrayList<>();
    static List<Integer> cipher_text = new ArrayList<>();
    static List<Integer> original_text = new ArrayList<>();

    public static void main(String[] args){
        encryption();
        decryption();
    }

    public static void encryption(){
        System.out.println("Plain text : " + plain_text);
        System.out.println("Key : " + key);
        System.out.println("n : " + n);
        // The initial state vector array
        for (int i = 0; i < Math.pow(2, n); i++) {
            S.add(i);
        }
        System.out.println("S : " + S);
        key_list = convertToDecimal(key);
        pt = convertToDecimal(plain_text);
        System.out.println("Plain text ( in array form ): "+ pt);
        // Making key_stream equal to length of state vector
        int diff = S.size() - key_list.size();
        if (diff != 0) {
            for (int i = 0; i < diff; i++) {
                key_list.add(key_list.get(i));
            }
        }
        System.out.println("Key list : " + key_list);
        KSA();
        PGRA();
        XOR();
    }

    public static void decryption(){
        S.clear();
        key_list.clear();
        pt.clear();
        key_stream.clear();
        // The initial state vector array
        for (int i = 0; i < Math.pow(2, n); i++) {
            S.add(i);
        }
        key_list = convertToDecimal(key);
        pt = convertToDecimal(plain_text);
        // Making key_stream equal to length of state vector
        int diff = S.size() - key_list.size();
        if (diff != 0) {
            for (int i = 0; i < diff; i++) {
                key_list.add(key_list.get(i));
            }
        }
        KSA();
        PGRA();
        do_XOR();
    }

    public static void KSA(){
        int j = 0;
        int N = S.size();
        // Iterate over the range [0, N]
        for (int i = 0; i < N; i++) {
            j = (j + S.get(i) + key_list.get(i)) % N;
            // Update S[i] and S[j]
            Collections.swap(S, i, j);
            System.out.println(i + " " + S);
        }
        System.out.println(
            "The initial permutation array is : " + S);
    }

    // PGRA algorithm
    public static void PGRA(){
        int N = S.size();
        int i = 0, j = 0;
        // Iterate over [0, length of pt]
        for (int k = 0; k < pt.size(); k++) {
            i = (i + 1) % N;
            j = (j + S.get(i)) % N;
            // Update S[i] and S[j]
            Collections.swap(S, i, j);
            System.out.println(k + " " + S);
            int t = (S.get(i) + S.get(j)) % N;
            key_stream.add(S.get(t));
        }
        System.out.println("Key stream : " + key_stream);
    }

    public static void XOR(){
        for (int i = 0; i < pt.size(); i++) {
            int c = key_stream.get(i) ^ pt.get(i);
            cipher_text.add(c);
        }
        // Convert the encrypted text to bits form
        String encrypted_to_bits = "";
        for (int i : cipher_text) {
            encrypted_to_bits += String.format("%0" + n + "d",Integer.parseInt(Integer.toBinaryString(i)));
        }
        System.out.println("Cipher text : "+ encrypted_to_bits);
    }

    public static void do_XOR(){
        for (int i = 0; i < cipher_text.size(); i++) {
            int p = key_stream.get(i) ^ cipher_text.get(i);
            original_text.add(p);
        }
        // Convert the decrypted text to the bits form
        String decrypted_to_bits = "";
        for (int i : original_text) {
            decrypted_to_bits += String.format("%0" + n + "d",Integer.parseInt(Integer.toBinaryString(i)));
        }
        System.out.println("Decrypted text : "+ decrypted_to_bits);
    }

    public static List<Integer> convertToDecimal(String input){
        List<String> list = new ArrayList<>();
        List<Integer> decimalList = new ArrayList<>();
        for (int i = 0; i < input.length(); i += n) {
            list.add(input.substring(
                i, Math.min(input.length(), i + n)));
        }
        for (String s : list) {
            decimalList.add(Integer.parseInt(s, 2));
        }
        return decimalList;
    }
}
