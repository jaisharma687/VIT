import java.util.*;
public class Pattern_4 {
	public static void main(String args[]) {
		Scanner numb = new Scanner(System.in);
		int n = numb.nextInt();
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1; j <= i ;j++) {
				System.out.print("  ");
			}
			for (int k = 1; k<=n-i+1;k++) {
				System.out.print(k+" ");
			}
			System.out.println("");
		}
	}
}
