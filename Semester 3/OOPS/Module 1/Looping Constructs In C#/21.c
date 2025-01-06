# include <stdio.h>
# include <string.h>
int main(){
    int pow,exp,val=1;
    scanf("%d %d",&pow,&exp);
    for(int i = 0; i<exp;i++){
        val *= pow;
    }
    printf("%d",val);
    return 0;
}