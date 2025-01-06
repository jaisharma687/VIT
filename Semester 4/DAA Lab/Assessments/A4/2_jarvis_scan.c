#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

int position(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void Convex_Hull(struct Point points[], int n) {
    if (n < 3)
        return;
    struct Point hull[n];
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    int hull_count = 0;
    do {
        hull[hull_count++] = points[p];
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (position(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != l);
    for (int i = 0; i < hull_count; i++)
        printf("%d %d\n", hull[i].x, hull[i].y);
}

int main() {
    int n;
    printf("Input:\n");
    scanf("%d",&n);
    struct Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    printf("The Boundary Coordinates are\n");
    Convex_Hull(points, n);
    return 0;
}