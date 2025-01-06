# include <stdio.h>

int TOH( int n , char a , char c , char b ){
    static int slno = 0;
    if(n>0){
        TOH(n-1,a,b,c);
        printf("%d move disk %d from %c to %c \n",++slno, n, a, c);
        TOH(n-1,b,c,a);
    }
}

int main(){
    int n;
    printf("How many disks ");
    scanf("%d",&n);
    TOH(n, 'A','C','B');
    printf("Done");
}