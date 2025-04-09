import java.math.BigInteger;
import java.util.Arrays;

public class SHA512 {
    private static long[] Message = new long[80];
    private static final long[] Constants = {
            0x428a2f98d728ae22L, 0x7137449123ef65cdL,
            0xb5c0fbcfec4d3b2fL, 0xe9b5dba58189dbbcL,
            0x3956c25bf348b538L, 0x59f111f1b605d019L,
            0x923f82a4af194f9bL, 0xab1c5ed5da6d8118L,
            0xd807aa98a3030242L, 0x12835b0145706fbeL,
            0x243185be4ee4b28cL, 0x550c7dc3d5ffb4e2L,
            0x72be5d74f27b896fL, 0x80deb1fe3b1696b1L,
            0x9bdc06a725c71235L, 0xc19bf174cf692694L,
            0xe49b69c19ef14ad2L, 0xefbe4786384f25e3L,
            0x0fc19dc68b8cd5b5L, 0x240ca1cc77ac9c65L,
            0x2de92c6f592b0275L, 0x4a7484aa6ea6e483L,
            0x5cb0a9dcbd41fbd4L, 0x76f988da831153b5L,
            0x983e5152ee66dfabL, 0xa831c66d2db43210L,
            0xb00327c898fb213fL, 0xbf597fc7beef0ee4L,
            0xc6e00bf33da88fc2L, 0xd5a79147930aa725L,
            0x06ca6351e003826fL, 0x142929670a0e6e70L,
            0x27b70a8546d22ffcL, 0x2e1b21385c26c926L,
            0x4d2c6dfc5ac42aedL, 0x53380d139d95b3dfL,
            0x650a73548baf63deL, 0x766a0abb3c77b2a8L,
            0x81c2c92e47edaee6L, 0x92722c851482353bL,
            0xa2bfe8a14cf10364L, 0xa81a664bbc423001L,
            0xc24b8b70d0f89791L, 0xc76c51a30654be30L,
            0xd192e819d6ef5218L, 0xd69906245565a910L,
            0xf40e35855771202aL, 0x106aa07032bbd1b8L,
            0x19a4c116b8d2d0c8L, 0x1e376c085141ab53L,
            0x2748774cdf8eeb99L, 0x34b0bcb5e19b48a8L,
            0x391c0cb3c5c95a63L, 0x4ed8aa4ae3418acbL,
            0x5b9cca4f7763e373L, 0x682e6ff3d6b2b8a3L,
            0x748f82ee5defb2fcL, 0x78a5636f43172f60L,
            0x84c87814a1f0ab72L, 0x8cc702081a6439ecL,
            0x90befffa23631e28L, 0xa4506cebde82bde9L,
            0xbef9a3f7b2c67915L, 0xc67178f2e372532bL,
            0xca273eceea26619cL, 0xd186b8c721c0c207L,
            0xeada7dd6cde0eb1eL, 0xf57d4f7fee6ed178L,
            0x06f067aa72176fbaL, 0x0a637dc5a2c898a6L,
            0x113f9804bef90daeL, 0x1b710b35131c471bL,
            0x28db77f523047d84L, 0x32caab7b40c72493L,
            0x3c9ebe0a15c9bebcL, 0x431d67c49c100d4cL,
            0x4cc5d4becb3e42b6L, 0x597f299cfc657e2aL,
            0x5fcb6fab3ad6faecL, 0x6c44198c4a475817L
    };

    private static String getHex(String bin) {
        switch (bin) {
            case "0000": return "0";
            case "0001": return "1";
            case "0010": return "2";
            case "0011": return "3";
            case "0100": return "4";
            case "0101": return "5";
            case "0110": return "6";
            case "0111": return "7";
            case "1000": return "8";
            case "1001": return "9";
            case "1010": return "a";
            case "1011": return "b";
            case "1100": return "c";
            case "1101": return "d";
            case "1110": return "e";
            case "1111": return "f";
            default: return "0";
        }
    }

    private static String decimalToHex(long deci) {
        String eqBin = String.format("%64s", Long.toBinaryString(deci)).replace(' ', '0');
        StringBuilder hexString = new StringBuilder();
        for (int i = 0; i < eqBin.length(); i += 4) {
            String temp = eqBin.substring(i, i + 4);
            hexString.append(getHex(temp));
        }
        return hexString.toString();
    }

    private static long binToDec(String bin) {
        return new BigInteger(bin, 2).longValue();
    }

    private static long rotateRight(long x, int n) {
        return (x >>> n) | (x << (64 - n));
    }

    private static long shiftRight(long x, int n) {
        return (x >>> n);
    }

    private static void separator(String getBlock) {
        Arrays.fill(Message, 0);
        int chunkNum = 0;
        for (int i = 0; i < getBlock.length(); i += 64, ++chunkNum) {
            if (i + 64 <= getBlock.length()) {
                Message[chunkNum] = binToDec(getBlock.substring(i, i + 64));
            }
        }
        
        for (int g = 16; g < 80; ++g) {
            long s0 = rotateRight(Message[g - 15], 1) ^ rotateRight(Message[g - 15], 8) ^ shiftRight(Message[g - 15], 7);
            long s1 = rotateRight(Message[g - 2], 19) ^ rotateRight(Message[g - 2], 61) ^ shiftRight(Message[g - 2], 6);
            Message[g] = Message[g - 16] + s0 + Message[g - 7] + s1;
        }
    }

    private static long maj(long a, long b, long c) {
        return (a & b) ^ (b & c) ^ (c & a);
    }

    private static long ch(long e, long f, long g) {
        return (e & f) ^ ((~e) & g);
    }

    private static long sigmaE(long e) {
        return rotateRight(e, 14) ^ rotateRight(e, 18) ^ rotateRight(e, 41);
    }

    private static long sigmaA(long a) {
        return rotateRight(a, 28) ^ rotateRight(a, 34) ^ rotateRight(a, 39);
    }

    private static void func(long[] vals, int k) {
        long a = vals[0];
        long b = vals[1];
        long c = vals[2];
        long d = vals[3];
        long e = vals[4];
        long f = vals[5];
        long g = vals[6];
        long h = vals[7];
        
        long t1 = h + ch(e, f, g) + sigmaE(e) + Message[k] + Constants[k];
        long t2 = sigmaA(a) + maj(a, b, c);
        
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
        
        vals[0] = a;
        vals[1] = b;
        vals[2] = c;
        vals[3] = d;
        vals[4] = e;
        vals[5] = f;
        vals[6] = g;
        vals[7] = h;
    }

    public static String sha512(String myString) {
        long A = 0x6a09e667f3bcc908L;
        long B = 0xbb67ae8584caa73bL;
        long C = 0x3c6ef372fe94f82bL;
        long D = 0xa54ff53a5f1d36f1L;
        long E = 0x510e527fade682d1L;
        long F = 0x9b05688c2b3e6c1fL;
        long G = 0x1f83d9abfb41bd6bL;
        long H = 0x5be0cd19137e2179L;
        long AA, BB, CC, DD, EE, FF, GG, HH;

        StringBuilder fixedStream = new StringBuilder();
        for (int i = 0; i < myString.length(); ++i) {
            String binary = String.format("%8s", Integer.toBinaryString(myString.charAt(i))).replace(' ', '0');
            fixedStream.append(binary);
        }

        String s1024 = fixedStream.toString();
        long oriLen = s1024.length();

        // Append '1' bit
        s1024 += "1";

        // Calculate padding
        int paddingLength = 896 - (s1024.length() % 1024);
        if (paddingLength < 0) {
            paddingLength += 1024;
        }

        // Add padding zeros
        for (int i = 0; i < paddingLength; i++) {
            s1024 += "0";
        }

        // Add original length as 128-bit big-endian integer
        String lengthBits = String.format("%128s", Long.toBinaryString(oriLen)).replace(' ', '0');
        s1024 += lengthBits;

        int blocksNumber = s1024.length() / 1024;
        int chunkNum = 0;
        String[] blocks = new String[blocksNumber];

        for (int i = 0; i < s1024.length(); i += 1024, ++chunkNum) {
            blocks[chunkNum] = s1024.substring(i, i + 1024);
        }

        for (int letsGo = 0; letsGo < blocksNumber; ++letsGo) {
            separator(blocks[letsGo]);
            AA = A;
            BB = B;
            CC = C;
            DD = D;
            EE = E;
            FF = F;
            GG = G;
            HH = H;

            long[] vals = new long[8];
            vals[0] = A;
            vals[1] = B;
            vals[2] = C;
            vals[3] = D;
            vals[4] = E;
            vals[5] = F;
            vals[6] = G;
            vals[7] = H;

            for (int count = 0; count < 80; count++) {
                func(vals, count);
            }

            A = AA + vals[0];
            B = BB + vals[1];
            C = CC + vals[2];
            D = DD + vals[3];
            E = EE + vals[4];
            F = FF + vals[5];
            G = GG + vals[6];
            H = HH + vals[7];
        }

        StringBuilder output = new StringBuilder();
        output.append(decimalToHex(A));
        output.append(decimalToHex(B));
        output.append(decimalToHex(C));
        output.append(decimalToHex(D));
        output.append(decimalToHex(E));
        output.append(decimalToHex(F));
        output.append(decimalToHex(G));
        output.append(decimalToHex(H));

        return output.toString();
    }

    public static void main(String[] args) {
        String[] strings = {"a", "abc", "message digest", "abcdefghijklmnopqrstuvwxyz", 
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
        
        for (String s : strings) {
            System.out.println("SHA('" + s + "') : \n" + sha512(s));
        }
    }
}
