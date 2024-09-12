//Jai Sharma
//22BEE0191
//ODD
//Question 1
class A {
    void info(){
        System.out.println("I am in parent class A");
    }
}
interface A1{
    void info();
}
interface A2{
    void info();
}
class A11 extends A implements A1 {
    public void info(){
        System.out.println("I am in child class A11");
    }
}
class A12 extends A implements A1,A2{
    public void info(){
        System.out.println("I am in child class A12");
    }
}
class A13 extends A implements A2{
    public void info(){
        System.out.println("I am in child class A13");
    }
}
class PAT41{
    public static void main(String arg[]){
        new A().info();
        new A11().info();
        new A12().info();
        new A13().info();
    }
}