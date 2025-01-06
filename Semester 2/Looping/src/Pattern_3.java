import java.util.*;
public class Pattern_3 {
	public static void main(String args[]) {
	Scanner numb = new Scanner(System.in);
	int b = numb.nextInt();
	for(int i = 1; i <=b;i++) {
		for(int j = b-1; j>=i;j--) {
			System.out.print("  ");
		}
		for(int k = i; k>0;k--) {
			System.out.print(k+" ");
		}
	System.out.println("");
	}
	
	}
}
