public class ECCPoint {
    static final int p = 11;
    static final int a = 1;
    static final int b = 6;

    static class Point{
        int x,y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static int modInv(int val, int mod){
        for(int i=1;i<mod;i++){
            if((val*i)%mod==1){
                return i;
            }
        }
        return -1;
    }

    public static Point findPoint(Point A, Point B){
        int x1 = A.x;
        int y1 = A.y;
        int x2 = B.x;
        int y2 = B.y;
        int lambda;
        if(x1==x2 & y1==y2){
            int den = modInv(2*y2, p);
            lambda = ((3*x1*x1+a)*den)%p;
        }else{
            int den = modInv((x1-x2+p)%p, p);
            lambda = (((y1-y2+p)%p)*den) % p;
        }
        int x3 = (lambda*lambda-x1-x2+p)%p;
        int y3 = (lambda*(x1-x3)-y1+p)%p;
        return new Point((x3+p)%p, (y3+p)%p);
    }
    public static void main(String[] args) {
        Point A = new Point(2, 4);
        Point B = new Point(2, 4);
        Point C = findPoint(A, B);
        int lhs = (C.y * C.y)%p;
        int rhs = (C.x*C.x*C.x + a*C.x+b)%p;
        System.out.println("Point C: ("+C.x+","+C.y+")");
        if(lhs == rhs){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
    }
}
