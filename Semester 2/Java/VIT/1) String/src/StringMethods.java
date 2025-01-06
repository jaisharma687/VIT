import java.lang.String;
public class StringMethods {
public static void main(String[] args) {
String str = "Thexyzwebsitexyzisxyzsoftwaretestingxyzhelp";
        String[] split = str.split("xyz");
        for (String obj: split) {
            System.out.println(obj);
        }
}
}

