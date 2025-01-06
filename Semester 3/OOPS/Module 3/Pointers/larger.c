# include <stdio.h>

int* larger(int *x,int *y)
{
    if(*x>*y)
        return x;
    else if(*y>*x)
        return y;
}

int main()
{
    int a =30;
    int b=20;
    int *p;
    p = larger(&a,&b);
    printf("Larger number is: %d",*p);
    return 0;
}