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
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    int b[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    int unionarray[n+m];
    int interarray[n+m];
    int u=n;
    int in=0;
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
            {
                interarray[in]= a[i];
                in++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        unionarray[i] = a[i];
    }
    for(int i=0;i<m;i++)
    {   
        int dup = 0;
        for(int j=0;j<n;j++)
        {
            if(b[i]==a[j])
            {
                dup++;
            }
        }
        if(dup==0)
        {
            unionarray[u++] = b[i]; 
        }
    }
    sort(interarray,in);
    sort(unionarray,u);
    for(int i=0;i<in;i++)
    {
        printf("%d ",interarray[i]);
    }
    printf("\n");
    for(int i=0;i<u;i++)
    {
        printf("%d ",unionarray[i]);
    }
    return 0;
}