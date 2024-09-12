#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100]; // Assuming a maximum input length of 100 characters
    printf("Enter a string: ");
    scanf("%s", inputString); // Read input as a single word (no spaces)

    // Splitting the input string into individual characters
    int length = strlen(inputString);
    for (int i = 0; i < length; i++) {
        printf("Character %d: %c\n", i, inputString[i]);
    }

    return 0;
}
