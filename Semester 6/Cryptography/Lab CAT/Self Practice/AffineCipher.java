public class AffineCipher {
    public static int modInverse(int n, int mod){
        for(int i=0;i<mod;i++){
            if((i*n)% mod == 1){
                return i;
            }
        }
        return -1;
    }

    public static String encrypt(String pt, int key1, int key2){
        StringBuilder res = new StringBuilder();
        for(char x: pt.toCharArray()){
            int ascii = (int)(x-'a');
            int shift1 = (ascii * key1)%26;
            int shift2 = (shift1 + key2)%26;
            char ch = (char)(shift2+'a');
            res.append(ch);
        }
        return res.toString();
    }

    public static String decrypt(String ct, int key1, int key2){
        StringBuilder res = new StringBuilder();
        int inv1 = modInverse(key1, 26);
        if(inv1 == -1){
            System.out.println("Enter valid key");
            return "";
        }
        for(char x: ct.toCharArray()){
            int ascii = (int)(x-'a');
            int shift2 = Math.abs((ascii-key2)%26);
            int shift1 = (shift2 * inv1)%26;
            char ch = (char)(shift1+'a');
            res.append(ch);
        }
        return res.toString();
    }
    
    public static void main(String[] args){
        String pt = "hello";
        int key1 = 7;
        int key2 = 2;
        String ct = encrypt(pt, key1, key2);
        System.out.println(ct);
        System.out.println(decrypt(ct,key1, key2));
    }
}
