#include <stdio.h>
#include <string.h>
int main(){
    char arr[100];
    scanf("%[^\n]%*c",arr);
    char fd = arr[0];
    // int len = strlen(arr);
    char ld = arr[strlen(arr)-1];
    printf("%c",ld);
    for(int i =1;i<strlen(arr)-1;i++){
        printf("%c",arr[i]);
    }
    printf("%c",fd);
    return 0;
}