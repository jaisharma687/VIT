#include <stdio.h>

typedef struct{
    int x,y;
}Point;

int cross(Point  p, Point q, Point r){
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if(val==0) return 0;
    return val > 0 ? 1 : 2;
}

void jarvisScan(Point p[],int n){
    if(n<3) return;
    Point hull[n];
    int hullCount = 0;
    int left = 0;
    for(int i=1;i<n;i++){
        if(p[i].x < p[left].x){
            left = i;
        } 
    }
    int current = left,next;
    do{
        hull[hullCount++] = p[current];
        next = (current + 1)%n;
        for(int i=0;i<n;i++){
            if(cross(p[current],p[i],p[next])==2){
                next = i;
            }
        }
        current = next;
    }while(current != left);
    for(int i=0;i<hullCount;i++){
        printf("%d %d\n",hull[i].x,hull[i].y);
    }
}

int main(){
    int n;
    printf("Value of n\n");
    scanf("%d",&n);
    printf("Inputs\n");
    Point points[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&points[i].x,&points[i].y);
    }
    printf("Boundary are:\n");
    jarvisScan(points,n);
    return 0;
}