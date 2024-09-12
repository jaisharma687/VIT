import java.util.*;
class TriangleProblem {
    public static void main (String arg[]){
        Scanner obj = new Scanner(System.in);
        int ax = obj.nextInt();
        int ay = obj.nextInt();
        int bx = obj.nextInt();
        int by = obj.nextInt();
        int cx = obj.nextInt();
        int cy = obj.nextInt();
        double a = Math.sqrt(Math.pow(bx-cx, 2)+Math.pow(by-cy, 2));
        double b = Math.sqrt(Math.pow(ax-cx, 2)+Math.pow(ay-cy, 2));
        double c = Math.sqrt(Math.pow(bx-ax, 2)+Math.pow(by-ay, 2));
        double A = Math.acos((Math.pow(a, 2)-Math.pow(b, 2)-Math.pow(c, 2))/(-2*b*c));
        double B = Math.acos((Math.pow(b, 2)-Math.pow(a, 2)-Math.pow(c, 2))/(-2*a*c));
        double C = Math.acos((Math.pow(c, 2)-Math.pow(b, 2)-Math.pow(a, 2))/(-2*b*a));
        System.out.println(a+" "+ Math.toDegrees(A));
        System.out.println(b+" "+ Math.toDegrees(B));
        System.out.println(c+" "+ Math.toDegrees(C));
        double s = (a+b+c)/2;
        System.out.println(s);
        double Ar = s*(s-a)*(s-b)*(s-c);
        System.out.println(Math.sqrt(Ar));
    }
}