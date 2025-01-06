# include <stdio.h>
# include <string.h>
int main(){
    char arr[100];
    int pdt=1;
    scanf("%[^\n]%*c",arr);
    int len = strlen(arr);
    for(int i = 0; i < len; i++){
        int a = (int)arr[i]; 
        int val = a-'0';
        printf("%d %d\n",val,a);
        pdt *= val;
    }
    printf("%d",pdt);
    return 0;
}