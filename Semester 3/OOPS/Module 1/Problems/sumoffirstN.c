#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    int count = 1;
    while (count<=n)
    {
        sum += count;
        count += 1;
    }
    printf("%d",sum);
    return 0;
    
}