import java.util.*;

public class warnsdorff {
    static int x[]={2,1,-1,-2,-2,-1,1,2};
    static int y[]={1,2,2,1,-1,-2,-2,-1};
    public static boolean tour(int n, int [][] arr, int count, int r, int c){
        if(count==(n*n)){
            return true;
        }
        for(int i=0;i<n;i++){
            int x1 = x[i]+r;
            int y1 = y[i]+c;
            if(x1>=0 && y1>=0 && x1<n && y1<n && arr[x1][y1]==0){
                arr[x1][y1]=count;
                if(tour(n,arr,count+1,x1,y1))
                    return true;
                arr[x1][y1]=0;
            }
        }
        return false;
    }
    static void print(int[][]arr,int n){
        for( int i=0;i<n;i++){
            for( int j=0;j<n;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int n = scanner.nextInt();
        int arr[][] = new int[n][n];
        arr[0][0] = 1;
        if(tour(n,arr,2,0,0))
            print(arr,n);
        scanner.close();
    }
}
