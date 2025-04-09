public class Keyed {
    public static String encrypt(String msg, int[] key){
        int n = key.length;
        StringBuilder ss = new StringBuilder();
        msg = msg.replaceAll(" ", "");
        while(msg.length()%n!=0){
            msg += 'z';
        }
        for(int i=0;i<msg.length();i+=n){
            char block[] = msg.substring(i, i+n).toCharArray();
            char p[] = new char[n];
            for(int j=0;j<n;j++){
                p[j] = block[key[j]-1];
            }
            ss.append(new String(p));
        }
        return ss.toString();
    }

    public static String decrypt(String msg, int[] key){
        int n = key.length;
        StringBuilder ss = new StringBuilder();
        for(int i=0;i<msg.length();i+=n){
            char block[] = msg.substring(i, i+n).toCharArray();
            char p[] = new char[n];
            for(int j=0;j<n;j++){
                p[key[j]-1] = block[j];
            }
            ss.append(new String(p));
        }
        return ss.toString();
    }

    public static void main(String[] args) {
        String ct = encrypt("enemy attacks tonight", new int[] {3,1,4,5,2});
        String pt = decrypt(ct, new int[] {3,1,4,5,2});
        System.out.println(ct.toUpperCase());
        System.out.println(pt.toUpperCase());
    }
}
