public class MultiplicativeCipher {
    public static int modInverse(int n, int mod){
        for(int i=0;i<mod;i++){
            if((i*n)% mod == 1){
                return i;
            }
        }
        return -1;
    }

    public static String encrypt(String pt, int key){
        StringBuilder res = new StringBuilder();
        for(char x: pt.toCharArray()){
            int ascii = (int)(x-'a');
            int shift = (ascii * key)%26;
            char ch = (char)(shift+'a');
            res.append(ch);
        }
        return res.toString();
    }

    public static String decrypt(String ct, int key){
        StringBuilder res = new StringBuilder();
        int inv = modInverse(key, 26);
        if(inv == -1){
            System.out.println("Enter valid key");
            return "";
        }
        for(char x: ct.toCharArray()){
            int ascii = (int)(x-'a');
            int shift = (ascii * inv)%26;
            char ch = (char)(shift+'a');
            res.append(ch);
        }
        return res.toString();
    }
    
    public static void main(String[] args){
        String pt = "hello";
        int key = 7;
        String ct = encrypt(pt, key);
        System.out.println(ct);
        System.out.println(decrypt(ct,key));
    }
}
