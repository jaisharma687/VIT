import java.util.*;

public class FrequencyAnalysisCipher {
    private static final String ENGLISH_FREQ = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    public static Map<Character, Integer> calculateFrequencies(String ciphertext) {
        Map<Character, Integer> frequencies = new HashMap<>();
        for (char c : ciphertext.toCharArray()) {
            if (Character.isLetter(c)) {
                char upperC = Character.toUpperCase(c);
                frequencies.put(upperC, frequencies.getOrDefault(upperC, 0) + 1);
            }
        }
        return frequencies;
    }

    public static Map<Character, Character> createMapping(Map<Character, Integer> freqs) {
        List<Map.Entry<Character, Integer>> freqList = new ArrayList<>(freqs.entrySet());
        freqList.sort((a, b) -> b.getValue().compareTo(a.getValue()));
        Map<Character, Character> mapping = new HashMap<>();
        for (int i = 0; i < freqList.size() && i < ENGLISH_FREQ.length(); i++) {
            mapping.put(freqList.get(i).getKey(), ENGLISH_FREQ.charAt(i));
        }
        return mapping;
    }

    public static String decrypt(String ciphertext, Map<Character, Character> mapping) {
        StringBuilder plaintext = new StringBuilder();
        for (char c : ciphertext.toCharArray()) {
            if (Character.isLetter(c)) {
                char upperC = Character.toUpperCase(c);
                char plainChar = mapping.getOrDefault(upperC, upperC);
                plaintext.append(Character.isLowerCase(c) ? Character.toLowerCase(plainChar) : plainChar);
            } else {
                plaintext.append(c);
            }
        }
        return plaintext.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the ciphertext: ");
        String ciphertext = scanner.nextLine();
        Map<Character, Integer> frequencies = calculateFrequencies(ciphertext);
        Map<Character, Character> mapping = createMapping(frequencies);
        String plaintext = decrypt(ciphertext, mapping);
        System.out.println("Decrypted plaintext: " + plaintext);
        scanner.close();
    }
}