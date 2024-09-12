# include <stdio.h>
# include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    int factors[100];
    for(int i = 2; i<n/2+1;i++){
        if(n%i==0){
            int prime =0;
            for(int j = 2; j < (i/2)+1 ; j++){
                if(i%j==0){
                    prime+=1;
                }
            }
            if(prime==0){
                printf("%d ",i);
            }
        }
    }
    
}