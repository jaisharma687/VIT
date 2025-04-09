public class MD5 {
    private static final int[] T = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };
    
    private static final int INIT_A = 0x67452301;
    private static final int INIT_B = 0xEFCDAB89;
    private static final int INIT_C = 0x98BADCFE;
    private static final int INIT_D = 0x10325476;
    
    private int[] state = new int[4];
    private long bitCount;
    private byte[] buffer = new byte[64];
    private byte[] digest = new byte[16];
    
    public MD5() {
        reset();
    }
    
    public void reset() {
        state[0] = INIT_A;
        state[1] = INIT_B;
        state[2] = INIT_C;
        state[3] = INIT_D;
        bitCount = 0;
        for (int i = 0; i < buffer.length; i++) {
            buffer[i] = 0;
        }
        for (int i = 0; i < digest.length; i++) {
            digest[i] = 0;
        }
    }
    
    private int F(int B, int C, int D) {
        return (B & C) | (~B & D);
    }
    
    private int G(int B, int C, int D) {
        return (B & D) | (C & ~D);
    }
    
    private int H(int B, int C, int D) {
        return B ^ C ^ D;
    }
    
    private int I(int B, int C, int D) {
        return C ^ (B | ~D);
    }
    
    private int rotateLeft(int x, int n) {
        return (x << n) | (x >>> (32 - n));
    }
    
    private void FF(int[] state, int a, int b, int c, int d, int x, int s, int ac) {
        state[a] = state[b] + rotateLeft((state[a] + F(state[b], state[c], state[d]) + x + ac), s);
    }
    
    private void GG(int[] state, int a, int b, int c, int d, int x, int s, int ac) {
        state[a] = state[b] + rotateLeft((state[a] + G(state[b], state[c], state[d]) + x + ac), s);
    }
    
    private void HH(int[] state, int a, int b, int c, int d, int x, int s, int ac) {
        state[a] = state[b] + rotateLeft((state[a] + H(state[b], state[c], state[d]) + x + ac), s);
    }
    
    private void II(int[] state, int a, int b, int c, int d, int x, int s, int ac) {
        state[a] = state[b] + rotateLeft((state[a] + I(state[b], state[c], state[d]) + x + ac), s);
    }
    
    private void bytesToWords(int[] output, byte[] input, int len) {
        int i, j;
        for (i = 0, j = 0; j + 3 < len; i++, j += 4) {
            output[i] = ((input[j] & 0xff)) |
                    ((input[j + 1] & 0xff) << 8) |
                    ((input[j + 2] & 0xff) << 16) |
                    ((input[j + 3] & 0xff) << 24);
        }
        
        // Handle remaining bytes with proper padding
        if (j < len) {
            output[i] = 0;
            for (int k = 0; j + k < len; k++) {
                output[i] |= ((input[j + k] & 0xff) << (k * 8));
            }
        }
    }
    
    private void transform(byte[] block) {
        int a = state[0];
        int b = state[1];
        int c = state[2];
        int d = state[3];
        int[] x = new int[16];
        
        bytesToWords(x, block, 64);
        
        // Save original values
        int aa = a;
        int bb = b;
        int cc = c;
        int dd = d;
        
        // Round 1
        FF(state, 0, 1, 2, 3, x[ 0],  7, T[ 0]);
        FF(state, 3, 0, 1, 2, x[ 1], 12, T[ 1]);
        FF(state, 2, 3, 0, 1, x[ 2], 17, T[ 2]);
        FF(state, 1, 2, 3, 0, x[ 3], 22, T[ 3]);
        FF(state, 0, 1, 2, 3, x[ 4],  7, T[ 4]);
        FF(state, 3, 0, 1, 2, x[ 5], 12, T[ 5]);
        FF(state, 2, 3, 0, 1, x[ 6], 17, T[ 6]);
        FF(state, 1, 2, 3, 0, x[ 7], 22, T[ 7]);
        FF(state, 0, 1, 2, 3, x[ 8],  7, T[ 8]);
        FF(state, 3, 0, 1, 2, x[ 9], 12, T[ 9]);
        FF(state, 2, 3, 0, 1, x[10], 17, T[10]);
        FF(state, 1, 2, 3, 0, x[11], 22, T[11]);
        FF(state, 0, 1, 2, 3, x[12],  7, T[12]);
        FF(state, 3, 0, 1, 2, x[13], 12, T[13]);
        FF(state, 2, 3, 0, 1, x[14], 17, T[14]);
        FF(state, 1, 2, 3, 0, x[15], 22, T[15]);
        
        // Round 2
        GG(state, 0, 1, 2, 3, x[ 1],  5, T[16]);
        GG(state, 3, 0, 1, 2, x[ 6],  9, T[17]);
        GG(state, 2, 3, 0, 1, x[11], 14, T[18]);
        GG(state, 1, 2, 3, 0, x[ 0], 20, T[19]);
        GG(state, 0, 1, 2, 3, x[ 5],  5, T[20]);
        GG(state, 3, 0, 1, 2, x[10],  9, T[21]);
        GG(state, 2, 3, 0, 1, x[15], 14, T[22]);
        GG(state, 1, 2, 3, 0, x[ 4], 20, T[23]);
        GG(state, 0, 1, 2, 3, x[ 9],  5, T[24]);
        GG(state, 3, 0, 1, 2, x[14],  9, T[25]);
        GG(state, 2, 3, 0, 1, x[ 3], 14, T[26]);
        GG(state, 1, 2, 3, 0, x[ 8], 20, T[27]);
        GG(state, 0, 1, 2, 3, x[13],  5, T[28]);
        GG(state, 3, 0, 1, 2, x[ 2],  9, T[29]);
        GG(state, 2, 3, 0, 1, x[ 7], 14, T[30]);
        GG(state, 1, 2, 3, 0, x[12], 20, T[31]);
        
        // Round 3
        HH(state, 0, 1, 2, 3, x[ 5],  4, T[32]);
        HH(state, 3, 0, 1, 2, x[ 8], 11, T[33]);
        HH(state, 2, 3, 0, 1, x[11], 16, T[34]);
        HH(state, 1, 2, 3, 0, x[14], 23, T[35]);
        HH(state, 0, 1, 2, 3, x[ 1],  4, T[36]);
        HH(state, 3, 0, 1, 2, x[ 4], 11, T[37]);
        HH(state, 2, 3, 0, 1, x[ 7], 16, T[38]);
        HH(state, 1, 2, 3, 0, x[10], 23, T[39]);
        HH(state, 0, 1, 2, 3, x[13],  4, T[40]);
        HH(state, 3, 0, 1, 2, x[ 0], 11, T[41]);
        HH(state, 2, 3, 0, 1, x[ 3], 16, T[42]);
        HH(state, 1, 2, 3, 0, x[ 6], 23, T[43]);
        HH(state, 0, 1, 2, 3, x[ 9],  4, T[44]);
        HH(state, 3, 0, 1, 2, x[12], 11, T[45]);
        HH(state, 2, 3, 0, 1, x[15], 16, T[46]);
        HH(state, 1, 2, 3, 0, x[ 2], 23, T[47]);
        
        // Round 4
        II(state, 0, 1, 2, 3, x[ 0],  6, T[48]);
        II(state, 3, 0, 1, 2, x[ 7], 10, T[49]);
        II(state, 2, 3, 0, 1, x[14], 15, T[50]);
        II(state, 1, 2, 3, 0, x[ 5], 21, T[51]);
        II(state, 0, 1, 2, 3, x[12],  6, T[52]);
        II(state, 3, 0, 1, 2, x[ 3], 10, T[53]);
        II(state, 2, 3, 0, 1, x[10], 15, T[54]);
        II(state, 1, 2, 3, 0, x[ 1], 21, T[55]);
        II(state, 0, 1, 2, 3, x[ 8],  6, T[56]);
        II(state, 3, 0, 1, 2, x[15], 10, T[57]);
        II(state, 2, 3, 0, 1, x[ 6], 15, T[58]);
        II(state, 1, 2, 3, 0, x[13], 21, T[59]);
        II(state, 0, 1, 2, 3, x[ 4],  6, T[60]);
        II(state, 3, 0, 1, 2, x[11], 10, T[61]);
        II(state, 2, 3, 0, 1, x[ 2], 15, T[62]);
        II(state, 1, 2, 3, 0, x[ 9], 21, T[63]);
        
        // Add the original values
        state[0] += aa;
        state[1] += bb;
        state[2] += cc;
        state[3] += dd;
    }
    
    public void update(byte[] input, int len) {
        int index = (int)((bitCount >> 3) & 0x3F);
        bitCount += (len << 3);
        int i = 0;
        int partLen = 64 - index;
        
        if (len >= partLen) {
            System.arraycopy(input, 0, buffer, index, partLen);
            transform(buffer);
            
            for (i = partLen; i + 63 < len; i += 64) {
                byte[] block = new byte[64];
                System.arraycopy(input, i, block, 0, 64);
                transform(block);
            }
            
            index = 0;
        }
        
        System.arraycopy(input, i, buffer, index, len - i);
    }
    
    public void complete() {
        byte[] bits = new byte[8];
        for (int i = 0; i < 8; i++) {
            bits[i] = (byte)((bitCount >>> (i * 8)) & 0xFF);
        }
        
        int index = (int)((bitCount >> 3) & 0x3F);
        int padLen = (index < 56) ? (56 - index) : (120 - index);
        
        byte[] padding = new byte[padLen];
        padding[0] = (byte)0x80;
        
        update(padding, padLen);
        update(bits, 8);
        
        for (int i = 0; i < 4; i++) {
            digest[i*4] = (byte)(state[i] & 0xFF);
            digest[i*4+1] = (byte)((state[i] >> 8) & 0xFF);
            digest[i*4+2] = (byte)((state[i] >> 16) & 0xFF);
            digest[i*4+3] = (byte)((state[i] >> 24) & 0xFF);
        }
    }
    
    public String hash(String message) {
        reset();
        byte[] bytes = new byte[message.length()];
        for (int i = 0; i < message.length(); i++) {
            bytes[i] = (byte)message.charAt(i);
        }
        update(bytes, bytes.length);
        complete();
        return bytesToHex(digest);
    }
    
    private String bytesToHex(byte[] bytes) {
        char[] hexChars = new char[bytes.length * 2];
        for (int j = 0; j < bytes.length; j++) {
            int v = bytes[j] & 0xFF;
            hexChars[j * 2] = "0123456789abcdef".charAt(v >>> 4);
            hexChars[j * 2 + 1] = "0123456789abcdef".charAt(v & 0x0F);
        }
        return new String(hexChars);
    }
    
    public static void main(String[] args) {
        MD5 md5 = new MD5();
        String[] S = {"a", "abc", "message digest", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
        for (String s : S) {
            System.out.println("MD5('" + s + "') : \n" + md5.hash(s));
        }
    }
}
