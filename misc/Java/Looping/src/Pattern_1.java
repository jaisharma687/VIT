import java.util.*;
public class Pattern_1 
{
	public static void main(String args[])
	{
	Scanner numb = new Scanner(System.in);
	int n = numb.nextInt();
	for(int i = 1; i <=n ; i++ ) {
		for(int j = 1; j<=i ; j++) {
		System.out.print(j+" ");
		}
		System.out.println("");
	}
	}
}

