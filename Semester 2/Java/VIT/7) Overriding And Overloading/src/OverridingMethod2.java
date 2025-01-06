class Parentclass100{
    //Overridden method
    void display2(){
   System.out.println("Parent class method");
    }
   }
   class Subclass100 extends Parentclass100{
    //Overriding method
    void display2(String msg){
   System.out.println("Child Class method "+ msg);
    }
   public static void main(String args[]){
       Subclass100 obj= new Subclass100();
       obj.display2("Welcome to JAVA");
       obj.display2();
    }
   }
   
