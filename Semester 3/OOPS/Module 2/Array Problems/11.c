# include <stdio.h>

int main()
{
    int arr[10];
    int even = 0 ; 
    int odd = 0 ;
    for(int i = 0; i<10;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("odd: %d, even: %d",odd,even);
    return 0;
}