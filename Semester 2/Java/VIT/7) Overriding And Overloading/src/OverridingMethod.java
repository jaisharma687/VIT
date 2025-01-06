class Parent{
    //Overridden method
    void display(){
   System.out.println("Parent class method");
    }
   }
   class Sub extends Parent{
    //Overriding method
    void display(){
   System.out.println("Child class method");
    }
    void printMsg(){
   //This would call Overriding method
   super.display();
   //This would call Overridden method
   display();
    }
    public static void main(String args[]){
       Sub obj= new Sub();
       obj.printMsg();
    }
   }
   
