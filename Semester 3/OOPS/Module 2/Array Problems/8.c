# include <stdio.h>

int main()
{
    int arr[10];
    for(int i =0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int del,pos;
    scanf("%d",&del);
    for(int i = 0;i<10;i++)
    {
        if(del == arr[i])
        {
            pos = i;
        }
    }
    for(int i =pos;i<10;i++)
    {
        arr[i] = arr[i+1];
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}