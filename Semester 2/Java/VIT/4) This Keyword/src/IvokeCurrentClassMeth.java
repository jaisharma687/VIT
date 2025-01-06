class A{
    void m(){System.out.println("hello m");}
    void n(){
        System.out.println("hello n");
        //m();//same as this.m();
        this.m();
    }
}
class IvokeCurrentClassMeth {
    public static void main(String arg[]){
        A a = new A();
        a.n();
    }
}
