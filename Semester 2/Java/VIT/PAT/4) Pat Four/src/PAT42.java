//Jai Sharma
//22BEE0191
//ODD
//Question 2
class F{
    final void walk(){
        System.out.println("Walking");
    }
}
class G extends F{
    void walk(){
        System.out.println("Walk");
    }
}
class PAT42{
    public static void main(String arg[]){
        new G().walk();
        /* it throws an error because when we apply final keyword we cannot change the 
        innner code statements, so when we are overriding the walk() method in the
        above code we wont be able to get any output
        But when we write new F().walk(); no error will be thrown as it is not 
        changing the value of the final keyword method */
    }
}