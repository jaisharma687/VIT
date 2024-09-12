# include <stdio.h>
int top = -1;
int queue[8];
int IsQueueFullEmpty(int x){
    if(top == -1){
        printf("Queue empty");
    }
    else if(top == x-1){
        printf("Queue full");
    }
    return 0;
}
int display(int x){
    for(int i=0;i<x;i++){
        printf("%d ",queue[i]);
    }
    return 0;
}
int push(int x){
    int i,y;
    for(i =0;i<x;i++){
        scanf("%d",&y);
        queue[i]=y;
        top++;
    }
    return 0;
}
void pop(int x){
    for(int i = 0; i<x; i++){
        for(int j = 0; j<x ;j++){
            queue[j]=queue[j+1];
        }
        display(x-i-1);
        if(top==0){
            top--;
        }
        else{
            top--;
            printf("\n");
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    IsQueueFullEmpty(n);
    printf("\n");
    push(n);
    display(n);
    printf("\n");
    IsQueueFullEmpty(n);
    printf("\n");
    pop(n);
    IsQueueFullEmpty(n);
    return 0;
}