import java.util.*;

public class segmented_sieve {
    public static List<Integer> sieve(int r){
        boolean[] prime = new boolean[r+1];
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        for(int i=2;i*i<=r;i++){
            if(prime[i]){
                for(int j=i*i;j<=r;j+=i) {
                    prime[j] = false;
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        for(int i=2;i<=r;i++){
            if(prime[i]) res.add(i);
        }
        return res;
    }

    public static void segmentedSieve(int l, int r){
        // if (l < 2) l = 2;
        List<Integer> prime = sieve((int)Math.sqrt(r));
        boolean[] isPrime = new boolean[r-l+1];
        Arrays.fill(isPrime, true);

        for(int p:prime){
            int start = Math.max(p*p, l + (p - l % p) % p);
            for(int j=start;j<=r;j+=p){
                isPrime[j-l] = false;
            }
        }

        for(int i=0;i<=r-l;i++){
            if(isPrime[i]) System.out.print((i+l)+" ");
        }
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter L");
        int l = sc.nextInt();
        System.out.println("Enter R");
        int r = sc.nextInt();
        segmentedSieve(l, r);
        sc.close();
    }
}
