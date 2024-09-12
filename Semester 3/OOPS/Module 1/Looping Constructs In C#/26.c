# include <stdio.h>
# include <string.h>
int main(){
    long long n;
    scanf("%lld",&n);
    int y = n/2+1;
    int prime = 0;
    for(int i=2 ; i<y ; i++){
        if(n%i==0){
            prime+=1;
        }
    }
    if(prime!=0){
        printf("not prime");
    }
    else{
        printf("prime");
    }
}