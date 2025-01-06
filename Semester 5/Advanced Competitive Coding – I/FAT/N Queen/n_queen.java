import java.util.*;

public class n_queen {
    static boolean isSol(int n, int[] arr){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = j - i;
                int y = arr[j] - arr[i];
                if(x==Math.abs(y)) return false;
            }
        }
        return true;
    }
    static boolean solve(int n, boolean[] visited, int[] pos, List<Integer> sol){
        if(sol.size()==n){
            if(isSol(n,pos))
                return true;
            else return false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                sol.add(i);
                pos[sol.size()-1] = i;
                if(solve(n,visited,pos,sol)){
                    return true;
                }
                else{
                    visited[i] = false;
                    sol.remove(sol.size()-1);
                }
            }
        }
        return false;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        boolean[] visited = new boolean[n];
        List<Integer> sol = new ArrayList<Integer>();
        int[] pos = new int[n];
        for(int i=0;i<n;i++){ 
            visited[i] = false; 
            pos[i] = -1;
        }
        solve(n,visited,pos,sol);
        for(int x: sol){
            for(int i=0;i<n;i++){
                if(x==i) System.out.print("1 ");
                else System.out.print("0 ");
            }
            System.out.println("");
        }
        scanner.close();
    }
}
