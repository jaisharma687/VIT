import java.util.*;

public class toggle_the_switch {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[] doors = new boolean[n+1];
        Arrays.fill(doors, false);
        int i,j,c=0;
        int o=0;
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j+=i){
                doors[j] = !doors[j];
            }
        }
        for(i=1;i<=n;i++){
            if(doors[i]) o++;
            else c++;
        }
        System.out.print("Open Doors: ");
        System.out.println(o);
        System.out.print("Closed Doors: ");
        System.out.println(c);
        sc.close();
    }
}