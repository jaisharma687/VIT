# include <stdio.h>

int main()
{
    int array[10];
    int sum = 0;
    for(int i = 0; i<10;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i = 0; i<10;i++)
    {
        sum += array[i];
    }
    printf("%d",sum);
    return 0;
}