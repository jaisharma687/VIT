public class CaesarCipher {
    public static String encrypt(String pt, int key){
        StringBuilder res = new StringBuilder();
        for(char x: pt.toCharArray()){
            int ascii = (int)(x-'a');
            int shift = (ascii + key)%26;
            char ch = (char)(shift+'a');
            res.append(ch);
        }
        return res.toString();
    }

    public static void decrypt(String ct){
        for(int key=1;key<26;key++){
            StringBuilder res = new StringBuilder();
            for(char x: ct.toCharArray()){
                int ascii = (int)(x-'a');
                int shift = Math.abs((ascii - key)%26);
                char ch = (char)(shift+'a');
                res.append(ch);
            }
            System.out.println("For key "+key+" : "+res);
        }
    }
    
    public static void main(String[] args){
        String pt = "hello";
        int key = 5;
        String ct = encrypt(pt, key);
        System.out.println(ct);
        decrypt(ct);
    }
}
