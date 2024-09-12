# include <stdio.h>
# include <string.h>
int main(){
    long long n;
    scanf("%lld",&n);
    long long y = n/2+1;
    for(long long i = 2;i<=y;i++){
        if(n%i==0){
            printf("%lld is a factor of %lld\n",i,n);
        }
    }
    return 0;
}