# include <stdio.h>

int factorial(int f)
{
    int fact = 1;
    for(int i =2; i<=f;i++)
    {
        fact *= i;
    }
    return fact;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            printf("%3c",' ');
        }
        for(int j = 0; j<=i;j++)
        {
            int val = factorial(i)/(factorial(j)*factorial(i-j));
            printf("%6d ",val);
        }
        printf("\n");
    }
    return 0;
}