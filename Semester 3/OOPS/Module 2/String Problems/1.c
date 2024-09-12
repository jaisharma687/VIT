#include <stdio.h>

int main() {
    char input_str[100];
    
    printf("Enter a string: ");
    scanf("%99[^\n]", input_str);
    printf("You entered: %s\n", input_str);
    return 0;
}
