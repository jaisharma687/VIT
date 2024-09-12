public class Palind{
    public static void main(String[] args) {
        String a = "spacecaps";
        int count = 0;
        for(int i = 0; i<a.length()/2;i++){
            if(a.charAt(i)==a.charAt(a.length()-i-1)){
                count += 0;
            }
            else{
                count +=1;
            }
        }
        System.out.println(count);
    }
}