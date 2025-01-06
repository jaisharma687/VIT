# include <stdio.h>
# include <string.h>

int main(){
    int val[10];
    long long n; 
    scanf("%lld",&n);
    for(int i=0;i<10;i++){
        val[i]=0;
    }
    int numb;
    for(int i =0;n!=0;i++){
        numb = n%10;
        n = n/10;
        val[numb] = val[numb]+1;
    }
    for(int i = 0; i<10;i++){
        printf("The frequency of %d : %d\n",i,val[i]);
    }
    return 0;
}