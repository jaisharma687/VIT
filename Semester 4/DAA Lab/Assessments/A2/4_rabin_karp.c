#include <stdio.h>
#include <string.h>
#include <math.h>

#define D 256

int hash(char str[], int len) {
    int hashVal = 0;
    for (int i = 0; i < len; i++) {
        hashVal = (hashVal * D + str[i]) % D;
    }
    return hashVal;
}

void rabinKarp(char text[], char pattern[]) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i, j;

    int patternHash = hash(pattern, patternLen);
    int textHash = hash(text, patternLen);

    for (i = 0; i <= textLen - patternLen; i++) {
        if (patternHash == textHash) {
            for (j = 0; j < patternLen; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == patternLen) {
                printf("The given pattern is present in the String\n");
                return;
            }
        }

        if (i < textLen - patternLen) {
            textHash = (D * (textHash - text[i] * (int)pow(D, patternLen - 1)) + text[i + patternLen]) % D;

            if (textHash < 0) {
                textHash += D;
            }
        }
    }

    printf("The given pattern is not present in the String\n");
}

int main() {
    char text[100], pattern[100];
    
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);

    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    rabinKarp(text, pattern);

    return 0;
}