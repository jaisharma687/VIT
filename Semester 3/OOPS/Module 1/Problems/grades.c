#include <stdio.h>
int main()
{
    int marks;
    scanf("%d",&marks);
    if(marks>100)
        printf("invalid");
    else if (100>=marks>90)
        printf("S");
    else if (90>=marks>80)
        printf("A");
    else if (80>=marks>70)
        printf("B");
    else 
        printf("F");
    return 0;
}