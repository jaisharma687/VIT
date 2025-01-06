# include <stdio.h>
int fact(int x){
    int val=1;
    for(int i = 1;i<=x;i++){
        val *= i;
    }
    return val;
}
int main(){
    int n,sum=0;
    scanf("%d",&n);
    int temp = n,rem;
    for(int i = 0;n!=0;i++){
        rem = n%10;
        n /= 10;
        sum += fact(rem);
    }
    if(temp == sum){
        printf("Strong number");
    }
    else{
        printf("Not Strong number");
    }
}