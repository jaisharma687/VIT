import java.util.*;

public class permutations{
    static void solve(String str, int n, HashMap<Character,Integer> freq, HashSet<String> res){
        if(str.length()==n){
            res.add(str);
            return;
        }
        for(int i=0;i<26;i++){
            char x = (char)(i+'A');
            if(freq.containsKey(x) && freq.get(x)>0){
                freq.put(x,freq.get(x)-1);
                solve(str+x,n,freq,res);
                freq.put(x,freq.get(x)+1);
            }
        }
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        HashMap<Character,Integer> freq = new HashMap<>();
        for(char x: input.toCharArray()){
            if(!freq.containsKey(x)){
                freq.put(x,1);
            }
            else freq.put(x,freq.get(x)+1);
        }
        HashSet<String> res = new HashSet<>();
        solve("",input.length(),freq,res);
        for(String x: res){
            System.out.println(x);
        }
        scanner.close();
    }
}