package Done;
import java.util.*;

public class FreqCipher {
    private static final String ENGLISH_FREQ = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    public static Map<Character, Integer> getFreq(String text) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : text.toUpperCase().replaceAll("[^A-Z]", "").toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        return freq;
    }

    public static Map<Character, Character> createMap(Map<Character, Integer> freq) {
        List<Character> chars = new ArrayList<>(freq.keySet());
        chars.sort((a, b) -> freq.get(b) - freq.get(a));
        
        Map<Character, Character> map = new HashMap<>();
        for (int i = 0; i < Math.min(chars.size(), ENGLISH_FREQ.length()); i++) {
            map.put(chars.get(i), ENGLISH_FREQ.charAt(i));
        }
        return map;
    }

    public static String decode(String cipher, Map<Character, Character> map) {
        StringBuilder result = new StringBuilder();
        for (char c : cipher.toCharArray()) {
            char decoded = map.getOrDefault(Character.toUpperCase(c), c);
            result.append(Character.isLowerCase(c) ? Character.toLowerCase(decoded) : decoded);
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.print("Enter ciphertext: ");
        String cipher = new Scanner(System.in).nextLine();
        System.out.println("Decrypted: " + decode(cipher, createMap(getFreq(cipher))));
    }
}
