# include <stdio.h>

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&array[i]);
    }
    int max, min;
    max = min = array[0];
    for (int i = 0; i < 10; i++)
    {
        if(array[i]>max)
        {
            max = array[i];
        }
        else if(array[i] < min)
        {
            min = array[i];
        }
    }
    printf("%d %d",max,min);
    return 0;
}
