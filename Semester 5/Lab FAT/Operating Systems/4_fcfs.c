#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int a, b, no, wt, tat, ct;
} Process;

Process read(int i) {
    Process p;
    printf("The process no.: %d\n", i + 1);
    p.no = i + 1;
    printf("Enter the arrival time: ");
    scanf("%d", &p.a);
    printf("Enter the burst time: ");
    scanf("%d", &p.b);
    return p;
}

void printResults(Process *p, int n, float awt, float att, int mct) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                p[i].no, p[i].a, p[i].b, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Completion Time: %d\n", mct);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

void fcfs(Process *p, int n) {
    int g[n+1];
    float att = 0, awt = 0;
    int mct = INT_MIN;
    g[0] = p[0].a;
    for (int i = 0; i < n; i++) {
        g[i + 1] = max(g[i] , p[i].a) + p[i].b;
        p[i].ct = g[i + 1];
        mct = max(mct, p[i].ct);
        p[i].tat = p[i].ct - p[i].a;
        p[i].wt = p[i].tat - p[i].b;
        awt += p[i].wt;
        att += p[i].tat;
    }
    awt /= n;
    att /= n;
    printResults(p, n, awt, att, mct);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *p = (Process *)malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        p[i] = read(i);
    }
    fcfs(p, n);
    free(p);
    return 0;
}