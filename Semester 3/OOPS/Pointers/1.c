# include <stdio.h>

int main()
{
    int var[] = {1,2,3,4,5,6};
    int *ip[6];
    for(int i=0; i<6;i++)
        ip[i] = &var[i];
    for(int i=0; i<6;i++)
        printf("%x,%x, %d\n",ip+i,ip[i],*ip[i]);
    char c = getchar();
    printf("%c\n",c);
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i] = 'A'+i;
        printf("%d %c\n",arr[i],arr[i]);
    }
}