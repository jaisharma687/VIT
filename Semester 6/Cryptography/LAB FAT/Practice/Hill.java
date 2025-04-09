import java.util.*;

public class Hill {
    static int K = 26;
    public static int modInverse(int val, int mod){
        for(int i=1;i<mod;i++){
            if((val*i)%mod==1){
                return i;
            }
        }
        return -1;
    }

    public static int[] matrixMultiply(int[][] key, int[] vec){
        int[] res = new int[3];
        for(int i=0;i<3;i++){
            int val = 0;
            for(int j=0;j<3;j++){
                val += key[i][j] * vec[j];
            }
            res[i] = val%K;
        }
        return res;
    }

    public static int[][] inverseKeyMatrix(int[][] key){
        int det =   key[0][0]*(key[1][1]*key[2][2]-key[2][1]*key[1][2])-
                    key[0][1]*(key[1][0]*key[2][2]-key[2][0]*key[1][2])+
                    key[0][2]*(key[1][0]*key[2][1]-key[2][0]*key[1][1]);
        det = (det % K + K) % K;

        int detInverse = modInverse(det, K);
        if(detInverse==-1){
            System.out.println("Det not invertible");
            return null;
        }

        return new int[][] {
            { (key[1][1]*key[2][2] - key[1][2]*key[2][1]) * detInverse % K,
              (key[0][2]*key[2][1] - key[0][1]*key[2][2]) * detInverse % K,
              (key[0][1]*key[1][2] - key[0][2]*key[1][1]) * detInverse % K },
            
            { (key[1][2]*key[2][0] - key[1][0]*key[2][2]) * detInverse % K,
              (key[0][0]*key[2][2] - key[0][2]*key[2][0]) * detInverse % K,
              (key[0][2]*key[1][0] - key[0][0]*key[1][2]) * detInverse % K },
            
            { (key[1][0]*key[2][1] - key[1][1]*key[2][0]) * detInverse % K,
              (key[0][1]*key[2][0] - key[0][0]*key[2][1]) * detInverse % K,
              (key[0][0]*key[1][1] - key[0][1]*key[1][0]) * detInverse % K }
        };
    }

    public static String prepareString(String text){
        StringBuilder ss = new StringBuilder(text);
        while(ss.length()%3!=0){
            ss.append('x');
        }
        return ss.toString();
    }

    public static String encrypt(String pt, int[][] key){
        pt = pt.toLowerCase();
        StringBuilder res = new StringBuilder();
        for(int i=0;i<pt.length();i+=3){
            int vec[] = {pt.charAt(i)-'a', pt.charAt(i+1)-'a', pt.charAt(i+2)-'a'};
            int ct[] = matrixMultiply(key, vec);
            for(int j=0;j<3;j++){
                res.append((char)((ct[j]+26)%26 + 'a'));
            }
        }
        return res.toString();
    }

    public static String decrypt(String ct, int[][] key){
        ct = ct.toLowerCase();
        int[][] invKey = inverseKeyMatrix(key);
        if(invKey==null){
            return "";
        }
        StringBuilder res = new StringBuilder();
        for(int i=0;i<ct.length();i+=3){
            int vec[] = {ct.charAt(i)-'a', ct.charAt(i+1)-'a', ct.charAt(i+2)-'a'};
            int pt[] = matrixMultiply(invKey, vec);
            for(int j=0;j<3;j++){
                res.append((char)((pt[j]+26)%26 + 'a'));
            }
        }
        return res.toString();
    }

    public static void main(String[] args) {
        int[][] key = {
            {6, 24, 1},
            {13, 16, 10},
            {20, 17, 15}
        };
        String ct = encrypt(prepareString("hello"), key);
        String pt = decrypt(ct, key);
        System.out.println(ct);
        System.out.println(pt);
    }
}
