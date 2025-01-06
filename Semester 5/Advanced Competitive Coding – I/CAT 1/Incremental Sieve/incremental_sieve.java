import java.util.*;

public class incremental_sieve {
    public static List<Integer> simpleSieve(int limit) {
        boolean[] prime = new boolean[limit + 1];
        Arrays.fill(prime, true);
        List<Integer> primes = new ArrayList<>();

        for (int p = 2; p * p <= limit; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= limit; i += p) {
                    prime[i] = false;
                }
            }
        }

        for (int p = 2; p <= limit; p++) {
            if (prime[p]) {
                primes.add(p);
            }
        }
        return primes;
    }

    public static void incrementalSieve(int start, int range) {
        int limit = (int) Math.sqrt(start + range) + 1;
        List<Integer> primes = simpleSieve(limit);

        for (int i = start; i <= range; i++) {
            boolean isPrime = true;
            for (int p : primes) {
                if (p * p > i) break;
                if (i % p == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime && i > 1) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the starting number (N): ");
        int start = sc.nextInt();
        System.out.print("Enter the range (number of numbers to check): ");
        int range = sc.nextInt();

        incrementalSieve(start, range);
        sc.close();
    }
}
