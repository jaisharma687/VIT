import java.util.*;

public class PlayFair {
    private static int SIZE = 5;
    public static char[][] generateKeyMatrix(String key){
        Set<Character> used = new HashSet<>();
        char matrix[][] = new char[SIZE][SIZE];
        StringBuilder ss = new StringBuilder();
        for(char x: key.toUpperCase().toCharArray()){
            if(x=='J') x='I';
            if(used.add(x)){
                ss.append(x);
            }
        }
        String s = ss.toString();
        int idx = 0;
        for(char x: s.toCharArray()){
            matrix[idx/SIZE][idx%SIZE] = x;
            idx++;
        }
        for(char x='A';x<='Z';x++){
            if(x=='J') continue;
            if(used.add(x)){
                matrix[idx/SIZE][idx%SIZE] = x;
                idx++;
            }
        }
        return matrix;
    }

    public static int[] findPosition(char[][] matrix, char s){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(matrix[i][j]==s){
                    return new int[]{i,j};
                }
            }
        }
        return new int[]{-1,-1};
    }

    public static String processText(char[][] matrix, String text, boolean encrypt){
        StringBuilder res = new StringBuilder();
        for(int i=0;i<text.length();i+=2){
            int pos1[] = findPosition(matrix, text.charAt(i));
            int pos2[] = findPosition(matrix, text.charAt(i+1));
            if(pos1[0]==pos2[0]){
                res.append(matrix[pos1[0]][(pos1[1]+((encrypt)?1:4))%SIZE]);
                res.append(matrix[pos2[0]][(pos2[1]+((encrypt)?1:4))%SIZE]);
            }
            else if(pos1[1]==pos2[1]){
                res.append(matrix[(pos1[0]+((encrypt)?1:4))%SIZE][pos1[1]]);
                res.append(matrix[(pos2[0]+((encrypt)?1:4))%SIZE][pos2[1]]);
            }
            else{
                res.append(matrix[pos1[0]][pos2[1]]);
                res.append(matrix[pos2[0]][pos1[1]]);
            }
        }
        return res.toString();
    }

    public static String prepareText(String text){
        StringBuilder ss = new StringBuilder();
        for(char x: text.toUpperCase().toCharArray()){
            if(x=='J') x='I';
            ss.append(x);
        }
        for(int i=0;i<ss.length();i+=2){
            if(i+1==ss.length() || ss.charAt(i)==ss.charAt(i+1)){
                ss.insert(i+1,'Z');
            }
        }
        return ss.toString();
    }
    public static void main(String[] args) {
        String key = "security";
        char matrix[][] = generateKeyMatrix(key);
        String pt = "hello";
        pt = prepareText(pt);
        String ct = processText(matrix, pt, true);
        System.out.println(pt+" "+ct);
        String pp = processText(matrix, ct, false);
        System.out.println(pp);
    }
}
