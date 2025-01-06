import java.util.*;
public class Pattern_6 {
	public static void main(String args[])
	{
		System.out.println("Enter the number: ");
		Scanner numb = new Scanner(System.in);
		int n = numb.nextInt();
		for(int i = 1; i <= n ; i++)
		{
			for(int j = n-i; j>=0 ; j--)
			{
				System.out.print("  ");
			}
			for(int k = i; k>0 ; k--)
			{
				System.out.print(k+" ");
			}
			for(int l = 2; l <= i ; l++)
			{
				System.out.print(l+" ");
			}
			System.out.println("");
		}
		for(int m = 1; m < n ; m++)
		{
			for(int j = 0; j<=m ; j++)
			{
				System.out.print("  ");
			}
			for(int k = n-m; k>0 ; k--)
			{
				System.out.print(k+" ");
			}
			for(int l = 2; l <= n-m ; l++)
			{
				System.out.print(l+" ");
			}
			System.out.println("");
		}
	}
}
