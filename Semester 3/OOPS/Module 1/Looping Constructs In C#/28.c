# include <stdio.h>
# include <string.h>
int main(){
    long long n;
    int sum = 0;
    scanf("%lld",&n);
    for(int i=2 ; i<=n ; i++){
        int prime = 0;
        for(int j = 2;j<i/2;j++){
            if(i%j==0){
                prime +=1;
            }
        }
        if(prime==0){
            printf("%d ",i);
            sum += i;
        }
    }
    printf("\n%d",sum);
    
}