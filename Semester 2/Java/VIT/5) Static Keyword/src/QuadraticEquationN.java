import java.math.*;
class QuadraticEquationN{
    static double a=1,b=2,c=1,d,r1,r2;
    public static double getDiscriminant(){
        d = b*b-4*a*c; 
        return Math.sqrt(d);
    }
    public static double getroot1(){
        r1 = (-b+getDiscriminant())/(2*a);
        return r1;
    }
    public static double getroot2(){
        r2 = (-b-getDiscriminant())/(2*a);
        return r2;
    }
}






