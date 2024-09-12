public class Pattern7 {
    public static void main(String[] args) {
        int n =7;
        for(int i = 1;i<=n ; i=i+2){
            for(int j = 1;j<=n-i;j=j+2){
                System.out.print("  ");
            }
            for(int k = 1; k<=i; k=k+2){
                System.out.print(k+"   ");
            }
            System.out.println();
        }
        int m = 3;
        int num =2;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<=i;j++){
                System.out.print("  ");
            }
            for(int k = 0;k<m-i;k++){
                System.out.print(num+"   ");
                num = num +2;
            }
            System.out.println();
        } 
    }
}
