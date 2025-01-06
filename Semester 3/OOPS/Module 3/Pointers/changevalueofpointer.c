# include <stdio.h>

void change(int *p)
{
    *p = *p +10;
}

int main()
{
    int x;
    x = 20;
    change(&x);
    printf("%d",x);
    return 0;
}