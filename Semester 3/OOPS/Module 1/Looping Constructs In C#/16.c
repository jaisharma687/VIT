# include <stdio.h>
# include <string.h>
int main(){
    char arr[15],rev[15];
    scanf("%[^\n]%*c",arr);
    int len = strlen(arr);
    for(int i =0;i<len;i++){
        rev[len-i-1] = arr[i];
    }
    for(int i =0;i<len;i++){
        printf("%c",rev[i]);
    }
    return 0;
}