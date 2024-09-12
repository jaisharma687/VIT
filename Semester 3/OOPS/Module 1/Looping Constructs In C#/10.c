# include <stdio.h>
int main(){
    int n,count=0;
    scanf("%d",&n);
    for(int i=0;n!=0;i++){
        n=n/10;
        count++;
    }
    printf("%d",count);
    return 0;
}