# include <stdio.h>

void input(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void display(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int binarysearch(int n,int arr[],int ele)
{
    int l = 0;
    int r = n-1;
    int found = 0;
    int mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(arr[mid]==ele)
        {
            found++;
            break;
        }
        else if(arr[mid]>ele)
            r = mid-1;
        else
            l = mid+1;
    }
    if(found)
        printf("Key found at position: %d",mid+1);
    else
        printf("Key not found");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    input(n,arr);
    display(n,arr);
    binarysearch(n,arr,59);
    return 0;
}