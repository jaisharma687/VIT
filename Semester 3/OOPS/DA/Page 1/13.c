# include <stdio.h>

int main()
{
    int n =120;
    int *p;
    p = &n;
    printf("Value of a and its address: %d & %x\n",*p,p);
    *p = 121;
    printf("Value of a and its address: %d & %x\n",*p,p);
    return 0;
}