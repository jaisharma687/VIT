# include <stdio.h>
# include <string.h>
int main(){
    int n1,n2,y;
    double lcm;
    scanf("%d %d",&n1, &n2);
    int hcf = 1;
    if(n1>n2){
        y = n2;
        for(int i = 2 ; i<=y ; i++){
            if(n1%i==0 && n2%i==0){
                hcf = i;
            }
        }
    }
    else if(n2>n1){
        y = n1;
        for(int i = 1 ; i<=y ; i++){
            if(n1%i==0 && n2%i==0){
                hcf = i;
            }
        }
    }
    else{
        hcf = n1;
    }
    lcm = (n1*n2)/hcf;
    printf("LCM of %d and %d is %.0f",n1,n2,lcm);
    return 0;
}