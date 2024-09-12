import java.util.*;
public class PrintMyName {
    public static void printMyName(String str){
        System.out.println(str);
        return;
    }
    public static void main(String[] args)  {
        Scanner st = new Scanner(System.in);
        String s = st.next();
        printMyName(s);
    }
}
