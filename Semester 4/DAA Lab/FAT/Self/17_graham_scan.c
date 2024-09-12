#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}Point;

Point p0;

Point nextToTop(Point *S, int *top){
    Point p = S[*top];
    (*top)--;
    Point res = S[*top];
    S[++(*top)] = p;
    return res;
}

void swap(Point *p1, Point *p2){
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int distSq(Point p1, Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int orientation(Point p, Point q, Point r){
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if(val==0) return 0;
    return (val>0) ? 1:2;
}

int compare(const void *vp1,const void *vp2){
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    int o = orientation(p0, *p1,*p2);
    if(o==0) return (distSq(p0,*p2) >= distSq(p0,*p1)) ? -1 : 1;
    return (o==2) ? -1 : 1;
}

void grahamScan(Point pts[],int n){
    int ymin = pts[0].y;
    int min = 0;
    for(int i=1;i<n;i++){
        int y = pts[i].y;
        if((ymin > y) || (y==ymin && pts[i].x < pts[min].x)){
            ymin = y;
            min = i;
        }
    }
    swap(&pts[0],&pts[min]);
    p0 = pts[0];
    qsort(&pts[1],n-1,sizeof(Point),compare);
    int m =1;
    for(int i=1;i<n;i++){
        while(i<n-1 && orientation(p0,pts[i],pts[i+1])==0){
            i++;
        }
        pts[m] = pts[i];
        m++;
    }
    if(m<3) return;
    Point S[n];
    int top = -1;
    S[++top] = pts[0];
    S[++top] = pts[1];
    S[++top] = pts[2];
    for(int i=3;i<m;i++){
        while(orientation(nextToTop(S,&top),S[top],pts[i])!=2){
            top--;
        }
        S[++top] = pts[i];
    }
    while(top>=0){
        Point p = S[top];
        printf("%d %d\n",p.x,p.y);
        top--;
    }
}

int main(){
    int n=8;
    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    printf("The Boundary Coordinates are\n");
    grahamScan(points, n);
    return 0;
}