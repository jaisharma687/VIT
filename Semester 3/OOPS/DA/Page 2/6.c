#include <stdio.h>

union MyUnion {
    int integer;
    float floating;
    char character;
};

int main() {
    union MyUnion myUnion;
    myUnion.integer = 42;
    printf("%d\n", myUnion.integer);
    myUnion.floating = 3.14;
    printf("%.2f\n", myUnion.floating);
    myUnion.character = 'A';
    printf("%c\n", myUnion.character);
    return 0;
}
