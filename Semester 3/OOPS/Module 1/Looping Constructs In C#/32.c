# include <stdio.h>
# include <string.h>
int main(){
    long long n;
    int val = 0;
    scanf("%lld",&n);
    long long y = n/2+1;
    for(long long i = 2;i<=y;i++){
        if(n%i==0){
            // printf("%lld is a factor of %lld\n",i,n);
            val += i;
        }
    }
    // printf("%d",val);
    if(val +1 == n){
        printf("Perfect number");
    }
    else{
        printf("Not Perfect number");
    }
}