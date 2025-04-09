import java.math.*;
import java.util.*;

public class RSA {
    public static int gcd(int a, int b){
        if(a==b) return a;
        if(a>b) return gcd(b,a-b);
        return gcd(a,b-a);
    }
    public static int modInverse(int val, int mod){
        for(int i=1;i<mod;i++){
            if((val*i)%mod==1){
                return i;
            }
        }
        return -1;
    }
    public static void RSA(int p, int q){
        int n = p*q;
        int phi = (p-1)*(q-1);
        System.out.println("n: "+n);
        System.out.println("phi: "+phi);
        int e = 2;
        while(e<phi){
            if(e!=p && e!=q && gcd(e,phi)==1){
                break;
            }
            e++;
        }
        int d = modInverse(e, phi);
        System.out.println("e: "+e);
        System.out.println("d: "+d);
        System.out.println("Public key: ("+e+","+n+")");
        System.out.println("Private key: ("+d+","+n+")");
        BigInteger PT = BigInteger.valueOf(12);
        BigInteger N = BigInteger.valueOf(n);
        BigInteger E = BigInteger.valueOf(e);
        BigInteger D = BigInteger.valueOf(d);
        BigInteger CT = PT.modPow(E, N);
        System.out.println("CT: "+CT);
        System.out.println("PT: "+CT.modPow(D, N));
    }
    public static void main(String[] args) {
        RSA(13,17);
    }
}
