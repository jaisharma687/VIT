//Jai Sharma
//22BEE0191
class PAT31{
    private double a,b,c,d,e,f;
    PAT31(double a,double b,double c,double d,double e,double f){
        this.a=a;
        this.b=b;
        this.c=c;
        this.d=d;
        this.e=e;
        this.f=f;
    }
    double getA(){return a;}
    double getB(){return b;}
    double getC(){return c;}
    double getD(){return d;}
    double getE(){return e;}
    double getF(){return f;}
    double isSolvable(){return a*d-b*c;}
    double getX(){return (e*d-b*f)/isSolvable();}
    double getY(){return (a*f-e*c)/isSolvable();}
}