#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int a, b, no, priority, wt, tat, ct;
} Process;

Process read(int i) {
    Process p;
    printf("The process no.: %d\n", i);
    p.no = i;
    printf("Enter the arrival time: ");
    scanf("%d", &p.a);
    printf("Enter the burst time: ");
    scanf("%d", &p.b);
    printf("Enter the priority: ");
    scanf("%d", &p.priority);
    return p;
}

void printResults(Process p[], float awt, float att, int mct, int n) {
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
            p[i].no, p[i].a, p[i].b, p[i].priority, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Completion Time: %d\n", mct);
}

int compare(const void *a, const void *b) {
    if(((Process *)a)->a == ((Process *)b)->a) return ((Process *)a)->priority - ((Process *)b)->priority;
    return ((Process *)a)->a - ((Process *)b)->a;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

void priorityScheduling(Process p[], int n) {
    int g[n + 1];
    float att = 0, awt = 0;
    int mct = INT_MIN;
    qsort(p, n, sizeof(Process), compare);
    g[0] = p[0].a;
    for (int i = 0; i < n; i++) {
        g[i + 1] = max(g[i], p[i].a) + p[i].b;
        p[i].ct = g[i + 1];
        mct = max(mct, p[i].ct);
        p[i].tat = p[i].ct - p[i].a;
        p[i].wt = p[i].tat - p[i].b;
        awt += p[i].wt;
        att += p[i].tat;
    }
    awt /= n;
    att /= n;
    printResults(p, awt, att, mct, n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i] = read(i);
    }
    priorityScheduling(p, n);
    return 0;
}
