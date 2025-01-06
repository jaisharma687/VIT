import java.util.*;

public class move_hyphen {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        if(input.contains("-")){
            int idx = input.indexOf("-");
            input = "-" + input.substring(0,idx) + input.substring(idx+1);
        }
        System.out.println(input);
        scanner.close();
    }
}