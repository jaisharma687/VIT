class RootProblem {
    private int a;
    private int b;
    private int c;
    RootProblem(int i, int j ,int k){
        a= i;
        b=j;
        c=k;
    }
    double getDiscriminant(){
        return b*b-4*a*c;
    }
    double getRoot1(){
        return (-b-Math.sqrt(getDiscriminant()))/(2*a);
    }
    double getRoot2(){
        return (-b+Math.sqrt(getDiscriminant()))/(2*a);
    }
}
