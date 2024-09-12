#include <stdio.h>

int size(int n){
    int l = 1;
    while(n/10>0){
        l++;
        n /= 10;
    }
    return l;
}

int power(int base, int exp){
    int val = 1;
    while(exp!=0){
        val *= base;
        exp--;
    }
    return val;
}

int karatsuba(int a, int b){
    int l1 = size(a);
    int l2 = size(b);
    int n = (l1<l2)?l1:l2;
    int num = (n+1)/2;
    if(a<10 && b<10){
        return a*b;
    }
    else{
        int p = a / power(10,num);
        int q = a % power(10,num);
        int r = b / power(10,num);
        int s = b % power(10,num);
        int x = karatsuba(p,r);
        int y = karatsuba(q,s);
        int z = karatsuba(p+q,r+s) - x -y;
        return x*power(10,num*2) + z * power(10,num) + y;
    }
}

int main(){
    int n1, n2;
    scanf("%d %d",&n1,&n2);
    printf("Multiplication of %d x %d is %d",n1,n2,karatsuba(n1,n2));
    return 0;
}