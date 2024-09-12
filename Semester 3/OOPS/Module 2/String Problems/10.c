#include <stdio.h>

int main() {
    char str[1000];
    int count[256] = {0};// Assuming ASCII characters
    printf("Input the string: ");
    fgets(str, sizeof(str), stdin);
    int i = 0;
    char maxChar = '\0';
    int maxCount = 0;
    while (str[i] != '\0') {
        char currentChar = str[i];
        if (currentChar >= 'a' && currentChar <= 'z') {
            int index = currentChar - 'a';
            count[index]++;
            if (count[index] > maxCount) {
                maxCount = count[index];
                maxChar = currentChar;
            }
        } 
        else if (currentChar >= 'A' && currentChar <= 'Z') {
            int index = currentChar - 'A';
            count[index]++;
            if (count[index] > maxCount) {
                maxCount = count[index];
                maxChar = currentChar;
            }
        }
        i++;
    }
    printf("The Highest frequency of character '%c' appears number of times: %d\n", maxChar, maxCount);
    return 0;
}
