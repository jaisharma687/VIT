#include <stdio.h>
int main(){
    int n,value=0;
    scanf("%d",&n);
    int temp = n;
    for(int i=0;n!=0;i++){
        int rem;
        rem = n%10;
        n /= 10;
        value += rem*rem*rem;
    }
    // printf("%d",value);
    if(value == temp){
        printf("Armstrong number");
    }
    else{
        printf("Not Armstrong number");
    }
}