public class ArrDiff {
    public static void main(String[] args) {
        int[] arr = {22, 32, 30, 48, 54, 26, 21};
        int[] diff = new int[arr.length-1];
        for(int i = 0; i<arr.length-1;i++){
            diff[i] = arr[i]-arr[i+1];
        }
        for(int i = 0; i<diff.length;i++){
            System.out.print(diff[i]+" ");
        }
    }
}
