import java.util.*;
public class Pattern_2 {
	public static void main(String args[]) {
	Scanner numb = new Scanner(System.in);
	int a = numb.nextInt();
	for(int i =1;i<=a;i++) {
		for(int j = 6;j>=i ;j--) {
			System.out.print((7-j)+" ");
		}
		System.out.println("");
	} 
	}
}
