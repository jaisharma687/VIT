# include <stdio.h>

int main()
{
    int n,search;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&search);
    int l=0;
    int r=n-1;
    int found = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid]==search)
        {
            printf("Key Element %d found in position:%d",arr[mid],mid);
            found++;
            break;
        }
        else if(arr[mid]>search)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }

    }
    if(found==0)
    {
        printf("Key not found");
    }
    return 0;
}