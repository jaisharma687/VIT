# include <stdio.h>

int main()
{
    int n,search;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&search);
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==search)
        {
            printf("Element %d found in position:%d",arr[i],i);
            found++;
        }
    }
    if(found==0)
    {
        printf("Key not found");
    }
    return 0;
}