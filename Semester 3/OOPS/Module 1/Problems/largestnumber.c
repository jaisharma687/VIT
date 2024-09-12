#include <stdio.h>
int main()
{
    int x,y,z;
    scanf("%d %d %d", &x,&y,&z);
    if(x>y && x>z)
        printf("%d", x);
    else if (y>x && y>z)
        printf("%d", y);
    else if (z>y && z>x)
        printf("%d", z);
    return 0;
}