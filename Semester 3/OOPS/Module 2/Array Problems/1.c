# include <stdio.h>

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&array[i]);
    }
    int large, small;
    int pos[2];
    large = small = array[0];
    for (int i = 0; i < 10; i++)
    {
        if(array[i]>large)
        {
            large = array[i];
            pos[0] = i;
        }
        else if(array[i] < small)
        {
            small = array[i];
            pos[1] = i;
        }
    }
    printf("%d %d %d %d",large,pos[0],small,pos[1]);
    return 0;
}
