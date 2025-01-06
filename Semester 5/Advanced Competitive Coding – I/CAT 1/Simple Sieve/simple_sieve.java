import java.util.*;
public class simple_sieve {
    public static void simpleSieve(int limit){
        boolean[] prime = new boolean[limit + 1];
        for(int i=2;i<limit;i++){
            prime[i] = true;
        }
        for(int j=2;j*j<limit;j++){
            if(prime[j]==true){
                for(int i=j*j;i<=limit;i+=j){
                    prime[i] = false;
                }
            }
        }
        for(int i=2;i<limit;i++){
            if(prime[i]==true){
                System.out.print(i + " ");
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        simpleSieve(num);
        sc.close();
    }
}
