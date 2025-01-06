class Superclass
{
 int num = 100;
}
class WithoutSuper extends Superclass
{
 /* The same variable num is declared in the Subclass which is already present in the Superclass */
 int num = 110;
 void printNumber(){
 System.out.println(num);
 }
 public static void main(String args[]){
	WithoutSuper obj= new WithoutSuper();
	obj.printNumber();
 }
}

