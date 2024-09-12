# include <stdio.h>

int main()
{
    int arr[10];
    int neg = 0;
    for(int i = 0; i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i =0;i<10;i++)
    {
        if(arr[i]<0)
        {
            neg++;
        }
    }
    printf("%d",neg);
    return 0;
}