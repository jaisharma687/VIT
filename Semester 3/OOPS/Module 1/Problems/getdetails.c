#include <stdio.h>

int main()
{
    int phone, age;
    float height;
    char sex;
    scanf("%d %d %f %c",&phone,&age,&height,&sex);
    printf("Phone number is %d\n", phone);
    printf("Age number is %d\n", age);
    printf("Height number is %f\n", height);
    printf("Sex %c\n", sex);
    return 0;
}