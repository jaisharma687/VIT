# include <stdio.h>

int main()
{
    int *p1,*p2,n1,n2;
    p1 = &n1;
    p2 = &n2;
    n1 = 100;
    n2 = 200;
    printf("Numbers are: %d & %d\n",*p1,*p2);
    int *temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
    printf("Swapped Numbers are: %d & %d",*p1,*p2);
    return 0;
}