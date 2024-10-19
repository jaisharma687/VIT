#include <stdio.h>

struct proc {
    int a;
    int b;
    int no;
    int wt;
    int tat;
};

struct proc read(int i) {
    struct proc p;
    printf("\n\nThe process no.:%d.\n", i);
    p.no = i;
    printf("Enter the arrival time: ");
    scanf("%d", &p.a);
    printf("Enter the burst time: ");
    scanf("%d", &p.b);
    return p;
}

int main() {
    struct proc p[10], temp;
    int n, g[10];
    float att = 0, awt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i] = read(i);
    }
    // sort on basis of arival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].a > p[j].a) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    g[0] = p[0].a;
    for (int i = 0; i < n; i++) {
        g[i + 1] = g[i] + p[i].b;
        p[i].wt = g[i] - p[i].a;
        p[i].tat = g[i + 1] - p[i].a;
        awt += p[i].wt;
        att += p[i].tat;
    }
    awt /= n;
    att /= n;
    printf("\n\tProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].no, p[i].a, p[i].b, p[i].wt, p[i].tat);
    }
    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);
    return 0;
}
