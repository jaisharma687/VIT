import java.util.*;
import java.math.*;

public class Idea {
    List<String> roundKeys = new ArrayList<String>();

    public void generateRoundKeys(String key) {
        roundKeys.clear(); // Clear existing keys before generating new ones
        for (int j = 0; j < 6; j++) {
            for (int i = 0; i < 8; i++) {
                roundKeys.add(key.substring(i * 16, (i + 1) * 16));
            }
            // Rotate the key by 25 bits
            key = key.substring(25) + key.substring(0, 25);
        }
        for (int i = 0; i < 4; i++) {
            roundKeys.add(key.substring(i * 16, (i + 1) * 16));
        }
    }
    
    public long modifiedMult(long xi, long ki) {
        if (xi == 0) xi = 65536;
        if (ki == 0) ki = 65536;
        long result = (xi * ki) % 65537;
        return result == 65536 ? 0 : result;
    }
    
    public long modifiedAdd(long xi, long ki) {
        return (xi + ki) % 65536;
    }
    
    private String formatBinaryString(long value) {
        return String.format("%16s", Long.toBinaryString(value)).replace(' ', '0');
    }
    
    public String oddRound(String plaintext, Map<Integer, List<Integer>> roundMap, int round) {
        long ka = Long.parseLong(roundKeys.get(roundMap.get(round).get(0)), 2);
        long kb = Long.parseLong(roundKeys.get(roundMap.get(round).get(1)), 2);
        long kc = Long.parseLong(roundKeys.get(roundMap.get(round).get(2)), 2);
        long kd = Long.parseLong(roundKeys.get(roundMap.get(round).get(3)), 2);
        long xa = Long.parseLong(plaintext.substring(0, 16), 2);
        long xb = Long.parseLong(plaintext.substring(16, 32), 2);
        long xc = Long.parseLong(plaintext.substring(32, 48), 2);
        long xd = Long.parseLong(plaintext.substring(48), 2);
        
        xa = modifiedMult(xa, ka);
        xb = modifiedAdd(xb, kb);
        xc = modifiedAdd(xc, kc);
        xd = modifiedMult(xd, kd);
        
        return formatBinaryString(xa) +
                formatBinaryString(xb) +
                formatBinaryString(xc) +
                formatBinaryString(xd);
    }
    
    public String evenRound(String plaintext, Map<Integer, List<Integer>> roundMap, int round) {
        long ke = Long.parseLong(roundKeys.get(roundMap.get(round).get(0)), 2);
        long kf = Long.parseLong(roundKeys.get(roundMap.get(round).get(1)), 2);
        long xa = Long.parseLong(plaintext.substring(0, 16), 2);
        long xb = Long.parseLong(plaintext.substring(16, 32), 2);
        long xc = Long.parseLong(plaintext.substring(32, 48), 2);
        long xd = Long.parseLong(plaintext.substring(48), 2);
        
        // Mangler function
        long yin = xa ^ xc;
        long zin = xb ^ xd;
        
        long yout = modifiedMult(modifiedAdd(yin, zin), ke);
        long zout = modifiedAdd(yout, modifiedMult(yin, kf));
        
        // Apply the mangler outputs
        long temp1 = xa ^ yout;
        long temp2 = xc ^ yout;
        long temp3 = xb ^ zout;
        long temp4 = xd ^ zout;
        
        // Swap middle values for next round
        return formatBinaryString(temp1) +
                formatBinaryString(temp3) +
                formatBinaryString(temp2) +
                formatBinaryString(temp4);
    }
    
    public String encrypt(String plaintext, String key) {
        Map<Integer, List<Integer>> roundMap = new HashMap<>();
        // Set up round key mapping for encryption
        for (int i = 1; i <= 8; i++) {
            roundMap.put(2*i-1, Arrays.asList((i-1)*6, (i-1)*6+1, (i-1)*6+2, (i-1)*6+3));
            roundMap.put(2*i, Arrays.asList((i-1)*6+4, (i-1)*6+5));
        }
        roundMap.put(17, Arrays.asList(48, 49, 50, 51));
    
        // Convert hex to binary
        BigInteger decimalplaintext = new BigInteger(plaintext, 16);
        String binaryplaintext = String.format("%64s", decimalplaintext.toString(2)).replace(' ', '0');
        BigInteger decimalkey = new BigInteger(key, 16);
        String binarykey = String.format("%128s", decimalkey.toString(2)).replace(' ', '0');
    
        generateRoundKeys(binarykey);
    
        for (int round = 1; round <= 17; round++) {
            if (round % 2 == 1) {
                binaryplaintext = oddRound(binaryplaintext, roundMap, round);
            } else {
                binaryplaintext = evenRound(binaryplaintext, roundMap, round);
            }
        }
        return String.format("%16s", new BigInteger(binaryplaintext, 2).toString(16)).replace(' ', '0').toUpperCase();
    }
    
    public String decrypt(String ciphertext, String key) {
        Map<Integer, List<Integer>> roundMap = new HashMap<>();
        // Set up round key mapping for decryption (inverse of encryption)
        roundMap.put(1, Arrays.asList(48, 49, 50, 51));
        for (int i = 1; i <= 8; i++) {
            int baseIdx = 48 - (i-1)*6;
            roundMap.put(2*i, Arrays.asList(baseIdx-2, baseIdx-1));
            roundMap.put(2*i+1, Arrays.asList(baseIdx-6, baseIdx-5, baseIdx-4, baseIdx-3));
        }
    
        // Convert hex to binary using BigInteger
        BigInteger decimalciphertext = new BigInteger(ciphertext, 16);
        String binaryciphertext = String.format("%64s", decimalciphertext.toString(2)).replace(' ', '0');
        BigInteger decimalkey = new BigInteger(key, 16);
        String binarykey = String.format("%128s", decimalkey.toString(2)).replace(' ', '0');
    
        generateRoundKeys(binarykey);
    
        // For decryption, we need to modify the keys
        List<String> modifiedKeys = new ArrayList<>(roundKeys);
        for (int i = 0; i < modifiedKeys.size(); i++) {
            if (i % 6 == 0 || i % 6 == 3) {
                // Multiplicative inverse for positions 0 and 3 in each round
                long keyVal = Long.parseLong(modifiedKeys.get(i), 2);
                if (keyVal == 0) keyVal = 65536;
                long invKey = modMultInverse(keyVal, 65537);
                modifiedKeys.set(i, formatBinaryString(invKey));
            } else if (i % 6 == 1 || i % 6 == 2) {
                // Additive inverse for positions 1 and 2 in each round
                long keyVal = Long.parseLong(modifiedKeys.get(i), 2);
                long invKey = (65536 - keyVal) % 65536;
                modifiedKeys.set(i, formatBinaryString(invKey));
            }
        }
        roundKeys = modifiedKeys;
    
        for (int round = 1; round <= 17; round++) {
            if (round % 2 == 1) {
                binaryciphertext = oddRound(binaryciphertext, roundMap, round);
            } else {
                binaryciphertext = evenRound(binaryciphertext, roundMap, round);
            }
        }
        return String.format("%16s", new BigInteger(binaryciphertext, 2).toString(16)).replace(' ', '0').toUpperCase();
    }
    
    // Calculate multiplicative inverse using Extended Euclidean Algorithm
    private long modMultInverse(long a, long m) {
        long m0 = m;
        long y = 0, x = 1;
    
        if (m == 1)
            return 0;
    
        while (a > 1) {
            long q = a / m;
            long t = m;
    
            m = a % m;
            a = t;
            t = y;
    
            y = x - q * y;
            x = t;
        }
    
        if (x < 0)
            x += m0;
    
        return x;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the plaintext(64 bit in hex): ");
        // String plaintext = sc.nextLine();
        String plaintext = "0011223344556677";
        System.out.println(plaintext);
        System.out.println("Enter the key(128 bit hex): ");
        // String key = sc.nextLine();
        String key = "0123456789ABCDEF0123456789ABCDEF";
        System.out.println(key);
    
        Idea idea = new Idea();
        String ciphertext = idea.encrypt(plaintext, key);
        System.out.println("Ciphertext: " + ciphertext);
    
        String decryptedText = idea.decrypt(ciphertext, key);
        System.out.println("Decrypted Text: " + decryptedText);
    
        sc.close();
    }
}