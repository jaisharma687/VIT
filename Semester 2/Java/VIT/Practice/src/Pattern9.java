public class Pattern9 {
    public static void main(String[] args) {
        int n = 3;
        for(int i =0; i<n;i++){
            for(int k = 0;k<=i;k++){
                System.out.print(" ");
            }
            for(int j =0;j<=n-i-1;j++){
                System.out.print("*");
            }
            for(int k = n-1-i; k>=1;k--){
                System.out.print("*");
            }
            System.out.println();
        }
        for(int i =n-2; i>=0;i--){
            for(int k = 0;k<=i;k++){
                System.out.print(" ");
            }
            for(int j =0;j<=n-i-1;j++){
                System.out.print("*");
            }
            for(int k = n-1-i; k>=1;k--){
                System.out.print("*");
            }
            System.out.println();
        }
    //     int m =2;
    //     for(int i = 0; i<m;i++){
    //         for(int k =0; k<i;k--){
    //             System.out.print(" ");
    //         }
    //         for(int j = 0;j<m+i;j++){
    //             System.out.print("*");
    //         }
    //         System.out.println();
    //     }
    }
}
