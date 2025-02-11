import java.util.*;
import java.math.*;

public class Idea {
    List<String> roundKeys = new ArrayList<String>();

    public void generateRoundKeys(String key) {
        for (int j = 0; j < 6; j++) {
            for (int i = 0; i < 8; i++) {
                roundKeys.add(key.substring(i * 16, (i + 1) * 16));
            }
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
        xd = modifiedMult(xd, kd);
        long temp = modifiedAdd(xb, kb);
        xb = modifiedAdd(xc, kc);
        xc = temp;
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
        long yin = xa ^ xb;
        long zin = xc ^ xd;
        // Mangler function
        long yout = modifiedMult(modifiedAdd(modifiedMult(ke, yin), zin), kf);
        long zout = modifiedAdd(modifiedMult(ke, yin), yout);
        xa ^= yout;
        xb ^= yout;
        xc ^= zout;
        xd ^= zout;
        return formatBinaryString(xa) +
                formatBinaryString(xb) +
                formatBinaryString(xc) +
                formatBinaryString(xd);
    }

    public String encrypt(String plaintext, String key) {
        Map<Integer, List<Integer>> roundMap = new HashMap<>();
        roundMap.put(1, Arrays.asList(0, 1, 2, 3));
        roundMap.put(2, Arrays.asList(4, 5));
        roundMap.put(3, Arrays.asList(6, 7, 8, 9));
        roundMap.put(4, Arrays.asList(10, 11));
        roundMap.put(5, Arrays.asList(12, 13, 14, 15));
        roundMap.put(6, Arrays.asList(16, 17));
        roundMap.put(7, Arrays.asList(18, 19, 20, 21));
        roundMap.put(8, Arrays.asList(22, 23));
        roundMap.put(9, Arrays.asList(24, 25, 26, 27));
        roundMap.put(10, Arrays.asList(28, 29));
        roundMap.put(11, Arrays.asList(30, 31, 32, 33));
        roundMap.put(12, Arrays.asList(34, 35));
        roundMap.put(13, Arrays.asList(36, 37, 38, 39));
        roundMap.put(14, Arrays.asList(40, 41));
        roundMap.put(15, Arrays.asList(42, 43, 44, 45));
        roundMap.put(16, Arrays.asList(46, 47));
        roundMap.put(17, Arrays.asList(48, 49, 50, 51));

        // hex to binary
        long decimalplaintext = Long.parseLong(plaintext, 16);
        String binaryplaintext = String.format("%64s", Long.toBinaryString(decimalplaintext)).replace(' ', '0');
        BigInteger decimalkey = new BigInteger(key, 16);
        String binarykey = String.format("%128s", decimalkey.toString(2)).replace(' ', '0');

        generateRoundKeys(binarykey);

        for (int round = 1; round < 18; round++) {
            if (round % 2 == 1) {
                binaryplaintext = oddRound(binaryplaintext, roundMap, round);
            } else {
                binaryplaintext = evenRound(binaryplaintext, roundMap, round);
            }
        }
        return String.format("%16s", new BigInteger(binaryplaintext, 2).toString(16)).replace(' ', '0');
    }

    public String decrypt(String ciphertext, String key) {
        Map<Integer, List<Integer>> roundMap = new HashMap<>();
        roundMap.put(1, Arrays.asList(48, 49, 50, 51));
        roundMap.put(2, Arrays.asList(46, 47));
        roundMap.put(3, Arrays.asList(44, 45, 42, 43));
        roundMap.put(4, Arrays.asList(40, 41));
        roundMap.put(5, Arrays.asList(38, 39, 36, 37));
        roundMap.put(6, Arrays.asList(34, 35));
        roundMap.put(7, Arrays.asList(32, 33, 30, 31));
        roundMap.put(8, Arrays.asList(28, 29));
        roundMap.put(9, Arrays.asList(26, 27, 24, 25));
        roundMap.put(10, Arrays.asList(22, 23));
        roundMap.put(11, Arrays.asList(20, 21, 18, 19));
        roundMap.put(12, Arrays.asList(16, 17));
        roundMap.put(13, Arrays.asList(14, 15, 12, 13));
        roundMap.put(14, Arrays.asList(10, 11));
        roundMap.put(15, Arrays.asList(8, 9, 6, 7));
        roundMap.put(16, Arrays.asList(4, 5));
        roundMap.put(17, Arrays.asList(0, 1, 2, 3));

        // hex to binary
        long decimalciphertext = Long.parseLong(ciphertext, 16);
        String binaryciphertext = String.format("%64s", Long.toBinaryString(decimalciphertext)).replace(' ', '0');
        BigInteger decimalkey = new BigInteger(key, 16);
        String binarykey = String.format("%128s", decimalkey.toString(2)).replace(' ', '0');

        generateRoundKeys(binarykey);

        for (int round = 1; round < 18; round++) {
            if (round % 2 == 1) {
                binaryciphertext = oddRound(binaryciphertext, roundMap, round);
            } else {
                binaryciphertext = evenRound(binaryciphertext, roundMap, round);
            }
        }
        return String.format("%16s", new BigInteger(binaryciphertext, 2).toString(16)).replace(' ', '0');
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
        

        Idea idea = new Idea();
        String ciphertext = idea.encrypt(plaintext, key);
        System.out.println("Ciphertext: " + ciphertext);

        String decryptedText = idea.decrypt(ciphertext, key);
        System.out.println("Decrypted Text: " + decryptedText);

        sc.close();
    }
}