#include <stdio.h>
#include<math.h>

int main()
{
    float radius, area, PI;
    PI = 3.14159265;
    scanf("%f",&radius);
    area = PI * radius * radius;
    printf("the area is %.0f", area);
    return 0;
}