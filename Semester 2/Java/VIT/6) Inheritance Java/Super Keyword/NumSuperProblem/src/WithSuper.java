class Superclass
{
 int num = 100;
}
class WithSuper extends Superclass
{
 int num = 110;
 void printNumber(){
/* Note that instead of writing num we are writing super.num in the 
print statement * this refers to the num variable of Superclass
*/
	System.out.println(super.num);
 }
 public static void main(String args[]){
	WithSuper obj= new WithSuper();
	obj.printNumber();
 }
}


