#include<stdio.h>

void sum() 
{
    static int a = 15;
    static int b = 35;
    printf("%d %d \n", a, b);
    a++;
    b++;
}
void main() 
{
    int i;
    for (i = 0; i < 3; i++)
        sum();
}