# include <stdio.h>
# include <string.h>
int main(){
    long long n,val = 1;
    scanf("%lld",&n);
    for(long long i = 1;i<=n;i++){
        val *= i;
    }
    printf("%lld is a factorial of %lld\n",val,n);
    return 0;
}