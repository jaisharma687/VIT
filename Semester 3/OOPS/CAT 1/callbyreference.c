# include <stdio.h>

void swap(int *x,int *y){
    int t;
    t =*x;
    *x = *y;
    *y = t;
}

int main(){
    int a = 20, b = 30;
    swap(&a,&b);
    printf("a = %d b = %d\n",a,b);
    return 0;
}
