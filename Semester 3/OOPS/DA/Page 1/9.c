# include <stdio.h>

int main()
{
    int *ptr1;
    int **ptr2;
    int a = 50;
    ptr1 = &a;
    ptr2 = &ptr1;
    printf("Value of a:%d\n",*ptr1);
    printf("Value of a:%d\n",**ptr2);
    printf("Address of a:%x\n",ptr1);
    printf("Address of a:%x\n",*ptr2);
    return 0;
}