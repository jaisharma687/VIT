class AA{
    AA(){System.out.println("Hello");}
    AA(int x){
        this();
        System.out.println(x);
    }
}
class BB{
    BB(){
        this(5);
        System.out.println("Hell");
    }
    BB(int x){
        System.out.println(x);
    }
}
class ThisForConstructors {
    public static void main(String arg[]){
        AA a = new AA();
        System.out.println();
        AA a1 = new AA(10);
        System.out.println();
        BB b = new BB(10);
        System.out.println();
        BB b1 = new BB();
    }
}
