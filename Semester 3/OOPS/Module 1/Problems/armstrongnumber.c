# include <stdio.h>
int main(){
    int n,rem,value = 0;
    scanf("%d",&n);
    int temp = n;
    for(int i =0; n!=0;i++)
    {
        rem = n%10;
        n = n/10;
        value = value + (rem * rem * rem);
    }
    // printf("%d %d", n,value);
    if(temp == value){
        printf("Number %d is Armstrong",temp);
    }
    else{
        printf("Number %d is not Armstrong",temp);
    }
}