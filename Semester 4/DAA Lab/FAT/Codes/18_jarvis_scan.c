#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y;
}Point;

int position(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y -q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void Convex_Hull(Point points[], int n) {
    if (n < 3)
        return;
    Point hull[n];
    int left = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[left].x)
            left = i;
    int current = left, next;
    int hull_count = 0;
    do {
        hull[hull_count++] = points[current];
        next = (current + 1) % n;
        for (int i = 0; i < n; i++) {
            if (position(points[current], points[i], points[next]) == 2)
                next = i;
        }
        current = next;
    } while (current != left);
    for (int i = 0; i < hull_count; i++)
        printf("%d %d\n", hull[i].x, hull[i].y);
}

int main() {
    int n;
    printf("Input:\n");
    scanf("%d",&n);
    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    printf("The Boundary Coordinates are\n");
    Convex_Hull(points, n);
    return 0;
}