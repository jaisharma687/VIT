#include <stdio.h>

int main()
{
    float x,y,sum,dif,pdt,div;
    scanf("%f%f",&x,&y);
    sum = x+y;
    dif = x-y;
    pdt = x*y;
    div = x/y;
    printf("\nsum is %f%f\n", sum);
    printf("\ndiff is %f%f\n", dif);
    printf("\npdt is %f%f\n", pdt);
    printf("\ndiv is %f%f\n", div);
    return 0;
}