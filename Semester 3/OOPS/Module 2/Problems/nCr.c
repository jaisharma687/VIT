# include <stdio.h>
long int factorial(int f){
    int i;
    long int fact = 1;
    if(f == 1 || f == 0){
        fact = 1;
    }
    else{
        for(i =2;i<=f;i++){
            fact *= i;
        }
    }
    return fact;
}

int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    long int nr,rr,nrr,ncr;
    nr = factorial(n);
    rr = factorial(r);
    nrr = factorial(n-r);
    long int nd = rr * nrr;
    ncr = nr/nd;
    printf("%d\n",ncr);
    printf("%d\n",rr);
    printf("%d\n",nrr);
    printf("%d\n",nr);
    printf("%d",nd);
}