public class Pattern6 {
    public static void main(String[] args) {
        int n = 6;
        for(int i= 0; i<=n;i++){
            for(int k = 0;k<=i;k++){
                System.out.print("  ");
            }
            for(int j = 1; j<=n-i;j++){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}
