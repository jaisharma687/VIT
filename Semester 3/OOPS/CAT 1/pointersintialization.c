#include <stdio.h>

int main(){
    int i = 3;
    int *j,**k;
    j = &i;
    k = &j;
    printf("%d\n",i);//value of i
    printf("%p\n",&i);//address of i
    printf("%d\n",*(&i));//value of i
    printf("\n");
    printf("%p\n",j);//value of j or address of i
    printf("%d\n",*j);//value of i
    printf("%p\n",&j);//address of j
    printf("%p\n",*(&j));//address of i
    printf("\n");
    printf("%p\n",k);//address of j
    printf("%d\n",**k);//value of i
    printf("%p\n",&(**k));//address of i
    printf("%p\n",*(&k));//address of j
    printf("%p\n",&k);//address of k
    printf("%p\n",*k);//value of j or address  of i
}