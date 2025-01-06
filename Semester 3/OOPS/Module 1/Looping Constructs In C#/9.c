#include <stdio.h>
int main()
{   
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=10;i++){
        int pdt;
        pdt = n*i;
        printf("%d * %d = %d\n",n,i,pdt);
    }
    return 0;
}