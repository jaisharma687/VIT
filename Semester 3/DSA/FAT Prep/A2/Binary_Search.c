# include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    printf("Enter the element to search: ");
    int s;
    scanf("%d",&s);
    int l =0;
    int r = n-1;
    int found =0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid]>s)
            r = mid-1;
        else if(arr[mid]<s)
            l = mid+1;
        else
        {
            found++;
            break;
        }
    }
    if(found)
        printf("Key found");
    else
        printf("Key not found");
}