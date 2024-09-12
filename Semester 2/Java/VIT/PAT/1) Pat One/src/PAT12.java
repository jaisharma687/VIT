import java.util.*;
public class PAT12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			Scanner numb = new Scanner(System.in);
			int n = numb.nextInt();
			int k = n;
			//String l = "";
			int l = 0;
			while(n>0) {
				int rem = n%10;
				//System.out.print(rem);
				n = n/10;
				l = l*10 + rem;
			}
			if(l==k) 
			{
				System.out.print("Its Palindrome");
			}
			else 
			{
				System.out.print("Not Palindrome");
			}	
	}

}
