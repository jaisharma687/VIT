public class PAT11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int n =1; n<=7; n=n+2) 
		{
			for(int j = 1; j<=7-n;j=j+2) 
			{
				System.out.print("  ");
			}
			for(int k = 1; k<=n;k++) 
			{
				if(k%2==1) 
				{
					System.out.print(k+" ");
				}
				else 
				{
					System.out.print("  ");
				}
			}
			System.out.println("");
		}
		for(int l= 2; l<=12;l=l+2)
		{
			System.out.print("  ");
			if(l<6) {
				System.out.print(l+" ");
			}
			else if(l==6) {
				System.out.println(l+" ");
				System.out.print("  ");
			}
			else if(l<10) {
				System.out.print(l+" ");
			}
			else if(l==10) {
				System.out.println(l+" ");
			}
			else{
				System.out.print("    ");
				System.out.println(l+" ");}}}}
