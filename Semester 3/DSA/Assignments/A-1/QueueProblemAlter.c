# include <stdio.h>
int n;
int front = -1;
int rear = -1;
int q[10];

void queuefullempty(){
    if(front == -1||front > rear){
        printf("Queue empty\n");
    }
    else if(rear == n-1){
        printf("Queue full\n");
    }
}

void display(){
    for(int i = front ; i<=rear ; i++){
        printf("%d ",q[i]);
    }
}

void enqueue(int x){
    if(front==-1){
        front++;
    }
    q[++rear]=x;
}

void dequeue(){
    front++;
    display();
}

int main(){
    scanf("%d",&n);
    queuefullempty();
    for(int i = 0; i<n;i++){
        int y;
        scanf("%d",&y);
        enqueue(y);
    }
    display();
    printf("\n");
    queuefullempty();
    for(int i = 0; i<n;i++){
        dequeue();
        if(i!=n-1){
            printf("\n");
        }
    }
    // printf("%d",front);
    queuefullempty();
}