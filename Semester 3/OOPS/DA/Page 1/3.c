# include <stdio.h>

int main()
{
    int *ptr,n;
    ptr = &n;
    n = 100;
    printf("Number is:%d\n",n);
    *ptr = 200;
    printf("New number is:%d",n);
    return 0;
}