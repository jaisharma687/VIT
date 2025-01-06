#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    int count = 0;
    while (count<=n)
    {
        sum += count;
        count += 2;
    }
    printf("%d",sum);
    return 0;
    
}