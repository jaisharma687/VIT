public class DESDecryption {
    // Inverse Initial Permutation (IP-1) table
    private static final int[] IP_INVERSE = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41, 9,  49, 17, 57, 25
    };

    // Expansion (E) table
    private static final int[] E = {
        32, 1,  2,  3,  4,  5,
        4,  5,  6,  7,  8,  9,
        8,  9,  10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32, 1
    };

    // S-Box table (example for S1 only)
    private static final int[][] S1 = {
        {14, 4,  13, 1,  2,  15, 11, 8,  3,  10, 6,  12, 5,  9,  0,  7},
        {0,  15, 7,  4,  14, 2,  13, 1,  10, 6,  12, 11, 9,  5,  3,  8},
        {4,  1,  14, 8,  13, 6,  2,  11, 15, 12, 9,  7,  3,  10, 5,  0},
        {15, 12, 8,  2,  4,  9,  1,  7,  5,  11, 3,  14, 10, 0,  6,  13}
    };

    // Permutation (P) table
    private static final int[] P = {
        16, 7,  20, 21,
        29, 12, 28, 17,
        1,  15, 23, 26,
        5,  18, 31, 10,
       2,  8,  24, 14,
       32, 27, 3,  9,
       19, 13, 30, 6,
       22, 11, 4,  25
    };

    // Helper function to apply a permutation
    public static String permute(String input, int[] permutationArray) {
        StringBuilder output = new StringBuilder();
        for (int i : permutationArray) {
            output.append(input.charAt(i - 1));
        }
        return output.toString();
    }

    // XOR operation
    private static String XOR(String a, String b) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            result.append(a.charAt(i) == b.charAt(i) ? '0' : '1');
        }
        return result.toString();
    }

    public static void main(String[] args) {
        // Ciphertext from the encryption process (after the first round)
        String ciphertext = "1111000010101010111100001010101010000111110011001001110110100000";
        String keyHex = "1111222233334444";
        StringBuilder keyBin = new StringBuilder();

        // Convert hex key to binary
        for (char c : keyHex.toCharArray()) {
            keyBin.append(String.format("%4s", Integer.toBinaryString(Integer.parseInt(String.valueOf(c), 16))).replace(' ', '0'));
        }

        // Split ciphertext into L1 and R1
        String L1 = ciphertext.substring(0, 32);
        String R1 = ciphertext.substring(32, 64);

        // Reverse the round
        String reversedL = R1;
        // Expand R1 using E table
        String expandedR1 = permute(R1, E);

        // XOR with the key (same key as encryption for simplicity)
        String XORed = XOR(expandedR1, keyBin.toString());

        // Perform S-box substitution (example with S1 only)
        StringBuilder substituted = new StringBuilder();
        for (int i = 0; i < 8; i++) {
            String sixBits = XORed.substring(i * 6, (i + 1) * 6);
            int row = Integer.parseInt(sixBits.substring(0, 1) + sixBits.substring(5, 6), 2);
            int col = Integer.parseInt(sixBits.substring(1, 5), 2);
            substituted.append(String.format("%4s", Integer.toBinaryString(S1[row][col])).replace(' ', '0'));
        }

        // Apply P permutation
        String permutedSubstitution = permute(substituted.toString(), P);

        // Compute R0 and L0
        String R0 = XOR(L1, permutedSubstitution);
        String L0 = reversedL;

        // Combine L0 and R0
        String combined = L0 + R0;

        // Apply inverse initial permutation (IP-1)
        String decrypted = permute(combined, IP_INVERSE);

        System.out.println("Decrypted plaintext (binary): " + decrypted);

        // Convert binary to hex for readability
        StringBuilder hexPlaintext = new StringBuilder();
        for (int i = 0; i < decrypted.length(); i += 4) {
            String nibble = decrypted.substring(i, i + 4);
            hexPlaintext.append(Integer.toHexString(Integer.parseInt(nibble, 2)).toUpperCase());
        }
        System.out.println("Decrypted plaintext (hex): " + hexPlaintext.toString());
    }
}
