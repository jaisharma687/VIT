#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindromicSubstring(char* str) 
{
    int n = strlen(str);
    if (n == 0) 
    {
        return "";
    }
    int table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    int start = 0;
    for (int i = 0; i < n; i++) 
    {
        table[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++) 
    {
        if (str[i] == str[i + 1]) 
        {
            table[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }
    for (int k = 3; k <= n; k++) 
    {
        for (int i = 0; i < n - k + 1; i++) 
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j]) 
            {
                table[i][j] = 1;
                if (k > maxLength) 
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    char* result = malloc(maxLength + 1);
    strncpy(result, str + start, maxLength);
    result[maxLength] = '\0';
    return result;
}

int main() 
{
    char input[] = "abcdcsdfabbccb";
    char* longest = longestPalindromicSubstring(input);
    printf("Original string: %s\n", input);
    printf("Longest Palindromic Substring from the said string: %s\n", longest);
    free(longest);
    return 0;
}