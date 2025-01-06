public class MaxArray {
    public static void main(String[] args) {
        int[] arr = {1, 7, 17, 65, 8, 12};
        int z = arr[0];
        for(int i =0; i<arr.length; i++){
            if(z<arr[i]){
                z = arr[i];
            }
        }
        System.out.println(z);
    }
}
