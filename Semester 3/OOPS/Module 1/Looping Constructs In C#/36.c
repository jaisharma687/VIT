# include <stdio.h>
int main(){
    int n,n1=0,n2=1,n3=0;
    scanf("%d",&n);
    printf("%d %d ",n1,n2);
    for(int i = 0; i<n ; i++){
        n3 = n1+n2;
        n1 = n2;
        n2 = n3;
        printf("%d ",n3);
    }
}