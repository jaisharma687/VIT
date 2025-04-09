import java.util.*;

public class DES {
    private static int[] permutationArray_64to56 = {
        57, 49, 41, 33, 25, 17, 9, 1,
        58, 50, 42, 34, 26, 18, 10, 2,
        59, 51, 43, 35, 27, 19, 11, 3,
        60, 52, 44, 36, 63, 55, 47, 39,
        31, 23, 15, 7, 62, 54, 46, 38,
        30, 22, 14, 6, 61, 53, 45, 37,
        29, 21, 13, 5, 28, 20, 12, 4
    };
    private static int[] permutationArray_56to48 = {
        14, 17, 11, 24, 1, 5, 3, 28,
        15, 6, 21, 10, 23, 19, 12, 4,
        26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40,
        51, 45, 33, 48, 44, 49, 39, 56,
        34, 53, 46, 42, 50, 36, 29, 32
    };
    public static int[] shiftArray = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    public static String rotate(String s, int shifts){
        return s.substring(shifts) + s.substring(0,shifts);
    }

    public static String permute(String input, int[] pArray){
        StringBuilder ss = new StringBuilder();
        for(int i: pArray){
            ss.append(input.charAt(i-1));
        }
        return ss.toString();
    }

    public static String hexToBin(String s){
        StringBuilder ss = new StringBuilder();
        for(char x: s.toCharArray()){
            switch (x) {
                case '0': ss.append("0000"); break;
                case '1': ss.append("0001"); break;
                case '2': ss.append("0010"); break;
                case '3': ss.append("0011"); break;
                case '4': ss.append("0100"); break;
                case '5': ss.append("0101"); break;
                case '6': ss.append("0110"); break;
                case '7': ss.append("0111"); break;
                case '8': ss.append("1000"); break;
                case '9': ss.append("1001"); break;
                case 'A': ss.append("1010"); break;
                case 'B': ss.append("1011"); break;
                case 'C': ss.append("1100"); break;
                case 'D': ss.append("1101"); break;
                case 'E': ss.append("1110"); break;
                case 'F': ss.append("1111"); break;
                default:
                    break;
            }
        }
        return ss.toString();
    }
    
    DES(String key){
        key = hexToBin(key);
        List<String> keys = new ArrayList<>();
        String p = permute(key, permutationArray_64to56);
        for(int i=0;i<16;i++){
            String left = rotate(p.substring(0,28), shiftArray[i]);
            String right = rotate(p.substring(28), shiftArray[i]);
            p = left + right;
            keys.add(permute(p, permutationArray_56to48));
        }
        for(int i=0;i<16;i++){
            System.out.println("Key "+i+" "+keys.get(i));
        }
    }

    public static void main(String[] args) {
        DES sol = new DES("0123456789ABCDEF");
    }
}
