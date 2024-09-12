#include <stdio.h>
int top = -1;
int n = 0;
int stack[100];
void IsEmptyFull(int x){
    if(top==-1){
        printf("Stack empty");
    }
    else if(top==x-1){
        printf("Stack full");
    }
}
void display(int y){
    int i;
    for(i=0;i<y;i++){
        printf("%d ",stack[i]);
    }
}
void push(){
    int i,x;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        stack[i]= x;
        top++;
    }
    
}
void pop(){
    int i;
    for(i=n-1;i>=0;i--){
        stack[i]=stack[i+1];
        top--;
        display(i);
        if(i!=0){
            printf("\n");
        }
    }
}
int main(){
    scanf("%d",&n);
    IsEmptyFull(n);
    printf("\n");
    push();
    display(n);
    printf("\n");
    IsEmptyFull(n);
    printf("\n");
    pop();
    IsEmptyFull(n);
    return 0;
}