class InvalidAge extends Exception{
	InvalidAge(String n){
		super(n);
	}
	// public String getMessage(){
	//     return "What Raaa!!!";
	// }
}
public class CE2 {
	static void validateAge(int age) throws InvalidAge{
		if(age<18){
			throw new InvalidAge("Enter valid age ");
		}
		else{
			System.out.println("Valid age");
		}
	}
	public static void main(String[] args) {
		try {
			validateAge(7);
		} catch (InvalidAge e) {
			System.out.println("Invalid age: "+ e.getMessage());
			System.out.println("Invalid age: "+ e);
		}
	}
}
