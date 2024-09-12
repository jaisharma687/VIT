# include <stdio.h>

int main()
{
    int array[10];
    for(int i = 0; i<10;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i = 1;i<10;i++)
    {
        for(int j =0;j<9;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array [j+1];
                array[j+1] = temp;
            }
        }
    }
    for(int i = 0; i<10;i++)
    {
        printf("%d ",array[i]);
    }
    int seclar = array[8];
    printf("\n%d",seclar);
    return 0;
}