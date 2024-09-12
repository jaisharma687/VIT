class Parentclass1{
    //no-arg constructor
    Parentclass1(){
        System.out.println("no-arg constructor of parent class");
    }
    //arg or parameterized constructor
    Parentclass1(String str){
        System.out.println("parameterized constructor of parent class " +str);
    }
}
   class Subclass extends Parentclass1{
    Subclass(){
        /* super() must be added to the first statement of constructor
        * otherwise you will get a compilation error. Another important
        * point to note is that when we explicitly use super in constructor
        * the compiler doesn't invoke the parent constructor automatically.*/
        super("Java");
        System.out.println("Constructor of child class");
    }
    void display(){
        System.out.println("Hello"); 
    }
    public static void main(String args[]){
        Subclass obj= new Subclass();
        obj.display();
    }
}
   
