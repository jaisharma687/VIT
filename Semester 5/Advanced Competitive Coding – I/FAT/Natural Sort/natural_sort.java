import java.util.*;

public class natural_sort {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        for(String x: input){
            System.out.println(x);
        }
        scanner.close();
    }
}
