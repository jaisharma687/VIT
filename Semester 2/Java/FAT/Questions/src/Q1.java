public class Q1 {
    public static void main(String[] args) {
        int n = 6;
        for(int i = 0;i<n;i++){
            for(int k = 0; k<n-i;k++){
                System.out.print("  ");
            }
            for(int j = i;j>=0;j--){
                System.out.print((j+1)+" ");
            }
            for(int l =0; l<i;l++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
