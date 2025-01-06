#include <stdio.h>

union IntBytes 
{
    int num;
    unsigned char bytes[sizeof(int)];
};

int main() 
{
    union IntBytes intUnion;
    printf("Enter an integer number: ");
    scanf("%d", &intUnion.num);
    printf("Integer in hex: %X\n", intUnion.num);
    printf("Bytes of the integer:\n");
    for (int i = 0; i < sizeof(int); i++)
        printf("Byte %d: %02X\n", i + 1, intUnion.bytes[i]);
    return 0;
}
