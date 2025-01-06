# include <stdio.h>

void areaperimeter(int r,float *a,float *p)
{
    *a = 3.14*r*r;
    *p = 2*3.14*r;
}

int main()
{
    int rad;
    float area,perimeter;
    printf("Enter the radius:\n");
    scanf("%d",&rad);
    areaperimeter(rad,&area,&perimeter);
    printf("%.2f %.2f",area,perimeter);
    return 0;
}