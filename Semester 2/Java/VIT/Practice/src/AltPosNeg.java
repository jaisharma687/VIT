public class AltPosNeg {
    public static void main(String[] args) {
        int arr[] = {1, 4, 9, 16, 9, 7, 4, 9, 11, 5};
        int value = arr[0];
        for(int i = 1; i<arr.length ; i++){
            if(i % 2 != 0){
                value = value - arr[i];
            }
            else{
                value = value  + arr[i];
            }
        }
        int fact = 1;
        for(int i = 1 ; i<=arr[9] ; i++){
            fact = fact * i;
        }
        System.out.println(value);
        System.out.println(fact);
    }
}
