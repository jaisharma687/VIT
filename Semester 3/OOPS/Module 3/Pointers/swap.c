# include <stdio.h>

void swap(int *a, int *b)
{
    int t;
    t= *a; 
    *a=*b ; 
    *b=t;
}
int main()
{
    int x=100,y=50;
    printf("Before swap %d and %d\n",x,y);
    swap(&x,&y);
    printf("After swap %d and %d",x,y);
    return 0;
}


