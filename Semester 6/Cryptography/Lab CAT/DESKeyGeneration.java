import java.util.*;

public class DESKeyGeneration {
    public static List<String> generateKey(String key_in) {
        int shiftArray[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
        List<String> key_out = new ArrayList<String>();
        String perm_1 = permutation1_64to56(key_in);
        String combine = perm_1;
        for (int i = 0; i < 16; i++) {
            String perm1_firstHalf = combine.substring(0, 28);
            String perm1_SecondHalf = combine.substring(28, 56);
            perm1_firstHalf = rotateLeft(perm1_firstHalf, shiftArray[i]);
            perm1_SecondHalf = rotateLeft(perm1_SecondHalf, shiftArray[i]);
            combine = perm1_firstHalf + perm1_SecondHalf;
            String perm_2 = permutation2_56to48(combine);
            key_out.add(perm_2);
        }
        return key_out;
    }

    public static String permutation1_64to56(String input) {
        int[] permutationArray = {
            57, 49, 41, 33, 25, 17, 9, 1,
            58, 50, 42, 34, 26, 18, 10, 2,
            59, 51, 43, 35, 27, 19, 11, 3,
            60, 52, 44, 36, 63, 55, 47, 39,
            31, 23, 15, 7, 62, 54, 46, 38,
            30, 22, 14, 6, 61, 53, 45, 37,
            29, 21, 13, 5, 28, 20, 12, 4
        };
        return permute(input, permutationArray);
    }

    public static String permutation2_56to48(String input) {
        int[] permutationArray = {
            14, 17, 11, 24, 1, 5, 3, 28,
            15, 6, 21, 10, 23, 19, 12, 4,
            26, 8, 16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55, 30, 40,
            51, 45, 33, 48, 44, 49, 39, 56,
            34, 53, 46, 42, 50, 36, 29, 32
        };
        return permute(input, permutationArray);
    }

    public static String rotateLeft(String input, int shifts) {
        return input.substring(shifts) + input.substring(0, shifts);
    }

    public static String permute(String input, int[] permutationArray) {
        StringBuilder output = new StringBuilder();
        for (int i : permutationArray) {
            output.append(input.charAt(i - 1));
        }
        return output.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please Enter the key (16 hexadecimal characters): ");
        String key_hex = sc.next();
        String key_bin = hextoBin(key_hex);
        List<String> key_after_each_step = generateKey(key_bin);
        for (int j = 0; j < 16; j++) {
            System.out.println("Key after iteration " + (j + 1) + ": " + key_after_each_step.get(j));
        }
        sc.close();
    }

    public static String hextoBin(String hex) {
        StringBuilder binary = new StringBuilder();
        for (char c : hex.toCharArray()) {
            switch (c) {
                case '0': binary.append("0000"); break;
                case '1': binary.append("0001"); break;
                case '2': binary.append("0010"); break;
                case '3': binary.append("0011"); break;
                case '4': binary.append("0100"); break;
                case '5': binary.append("0101"); break;
                case '6': binary.append("0110"); break;
                case '7': binary.append("0111"); break;
                case '8': binary.append("1000"); break;
                case '9': binary.append("1001"); break;
                case 'A': case 'a': binary.append("1010"); break;
                case 'B': case 'b': binary.append("1011"); break;
                case 'C': case 'c': binary.append("1100"); break;
                case 'D': case 'd': binary.append("1101"); break;
                case 'E': case 'e': binary.append("1110"); break;
                case 'F': case 'f': binary.append("1111"); break;
                default: throw new IllegalArgumentException("Invalid hexadecimal character: " + c);
            }
        }
        return binary.toString();
    }
}