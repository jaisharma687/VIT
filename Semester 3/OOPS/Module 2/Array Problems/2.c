# include <stdio.h>

int main()
{
    int array[10];
    for(int i = 0; i<10;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i = 0; i<10;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}