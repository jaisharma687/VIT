# include <stdio.h>

void sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int odd[n];
    int even[n];
    int o=0; 
    int e=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]%2==0)
        {
            even[e] = arr[i];
            e++;
        }
        else
        {
            odd[o] = arr[i];
            o++;
        }
    }
    sort(even,e);
    sort(odd,o);
    int sorted[e+o];
    for(int i = 0;i<e+o;i++)
    {
        if(i<o)
        {
            sorted[i] = odd[i];
        }
        else
        {
            sorted[i] = even[i-o];
        }
    }
    for(int i = 0;i<o+e;i++)
    {
        printf("%d ",sorted[i]);
    }
    return 0;
}