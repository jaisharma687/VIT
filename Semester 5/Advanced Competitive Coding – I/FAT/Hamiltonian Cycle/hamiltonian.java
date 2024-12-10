import java.util.*;

public class hamiltonian {
    static boolean isCycle(int n, int[] pos, int[][] matrix){
        for(int i=0;i<n-1;i++){
            if(matrix[pos[i]][pos[i+1]]!=1) return false;
        }
        return matrix[n-1][pos[0]]==1;
    }
    static boolean solve(int n, int[][] matrix, int[] pos,  List<Integer> sol, boolean[] visited){
        if(sol.size()==n){
            if(isCycle(n,pos,matrix)){
                return true;
            }
            return false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                sol.add(i);
                pos[sol.size()-1] = i;
                if(solve(n, matrix, pos, sol, visited)){
                    return true;
                }else{
                    sol.remove(sol.size()-1);
                    visited[i] = false;
                }
            }
        }
        return false;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] matrix = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = scanner.nextInt();
            }
        }
        List<Integer> sol = new ArrayList<>();
        int[] pos = new int[n];
        boolean[] visited = new boolean[n];
        System.out.println("Matrix: ");
        for(int i=0;i<n;i++){
            pos[i] = -1;
            visited[i] = false;
            for(int j=0;j<n;j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println("");
        }
        if(solve(n,matrix,pos,sol,visited)){
            sol.add(pos[0]);
            for(int i=0;i<n+1;i++){
                System.out.print(sol.get(i) + " ");
            }
        }
        scanner.close();
    }
}
