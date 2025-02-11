public class DESEncryption {

    // Initial Permutation (IP) table
    private static final int[] IP = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9,  1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
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
        String plaintextHex = "0123456789ABCDEF";
        String keyHex = "1111222233334444";
        StringBuilder plaintextBin = new StringBuilder();
        StringBuilder keyBin = new StringBuilder();

        // Convert hex to binary
        for (char c : plaintextHex.toCharArray()) {
            plaintextBin.append(String.format("%4s", Integer.toBinaryString(Integer.parseInt(String.valueOf(c), 16))).replace(' ', '0'));
        }
        for (char c : keyHex.toCharArray()) {
            keyBin.append(String.format("%4s", Integer.toBinaryString(Integer.parseInt(String.valueOf(c), 16))).replace(' ', '0'));
        }

        // Apply initial permutation (IP)
        String permutedPlaintext = permute(plaintextBin.toString(), IP);

        // Split into L0 and R0
        String L = permutedPlaintext.substring(0, 32);
        String R = permutedPlaintext.substring(32, 64);

        // Expand R0 using E table
        String expandedR = permute(R, E);

        // XOR with the key (assume K1 = key for simplicity)
        String XORed = XOR(expandedR, keyBin.toString());

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

        // Compute R1 and L1
        String newR = XOR(L, permutedSubstitution);
        String newL = R;

        // Combine L1 and R1
        String combined = newL + newR;

        System.out.println("Ciphertext after first round: " + combined);
    }
}
