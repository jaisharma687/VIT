#include <stdio.h>

union MyUnion {
    int integer;
    float floating_point;
    char character;
};

int main() {
    union MyUnion myUnion;
    printf("Size of the union: %lu bytes\n", sizeof(myUnion));
    return 0;
}