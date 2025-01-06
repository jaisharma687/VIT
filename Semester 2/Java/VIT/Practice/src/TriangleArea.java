public class TriangleArea {
    public static void main(String[] args) {
        double a = 3;
        double b = 4;
        double c = 5;
        double s = a+b+c/2;
        double ar = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        System.out.println(ar);
    }
}
