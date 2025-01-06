public class Pattern8 {
    public static void main(String[] args) {
        int n =5;
        for(int i = 0; i<=n ; i++){
            for(int j =i;j>=0;j--){
                System.out.print((n-j)+" ");
            }
            System.out.println();
        }
    }
}
