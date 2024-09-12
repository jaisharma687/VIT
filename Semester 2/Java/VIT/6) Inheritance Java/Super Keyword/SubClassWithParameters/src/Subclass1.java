class Parentclass{
    Parentclass(){
        System.out.println("Constructor of parent class");
    }
}
class Subclass1 extends Parentclass{
    Subclass1(){
        System.out.println("Constructor of child class");
    }
    Subclass1(int num){
        /* Even though it is a parameterized constructor. The compiler still adds the no-arg super() here*/
        System.out.println("arg constructor of child class");
    }
    void display(){
       System.out.println("Hello!");
    }
    public static void main(String args[]){
       Subclass1 obj= new Subclass1();
       obj.display();
       /* Creating second object using arg constructor it will invoke arg constructor of child class which will 
       invoke no-arg constructor of parent class automatically */
       Subclass1 obj2= new Subclass1(10);
       obj2.display();
    }
   }