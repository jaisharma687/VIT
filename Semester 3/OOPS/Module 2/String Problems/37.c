#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiplyStrings(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int lenResult = len1 + len2;
    int carry = 0;
    char* result = (char*)malloc((lenResult + 1) * sizeof(char));
    memset(result, '0', lenResult);
    result[lenResult] = '\0';
    for (int i = len1 - 1; i >= 0; i--) \
    {
        carry = 0;
        for (int j = len2 - 1; j >= 0; j--) 
        {
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    int startIndex = 0;
    while (startIndex < lenResult && result[startIndex] == '0') 
        startIndex++;
    if (startIndex == lenResult) 
    {
        char* zeroResult = (char*)malloc(2 * sizeof(char));
        zeroResult[0] = '0';
        zeroResult[1] = '\0';
        return zeroResult;
    }
    char* finalResult = (char*)malloc((lenResult - startIndex + 1) * sizeof(char));
    strcpy(finalResult, result + startIndex);
    free(result);
    return finalResult;
}

int main() 
{
    char num1[] = "100";
    char num2[] = "15";
    printf("Original numbers: %s and %s\n", num1, num2);
    char* product = multiplyStrings(num1, num2);
    printf("Multiple two said numbers represent as string? %s\n", product);
    free(product);
    return 0;
}
