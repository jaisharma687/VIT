#include <stdio.h>
#include <limits.h>

typedef struct {
    int no, a, b, priority, wt, tat, rt, ct;
} Process;

Process read(int i) {
    Process p;
    printf("The process no.: %d\n", i);
    p.no = i;
    printf("Enter the arrival time: ");
    scanf("%d", &p.a);
    printf("Enter the burst time: ");
    scanf("%d", &p.b);
    p.rt = p.b;
    printf("Enter the priority: ");
    scanf("%d", &p.priority);
    return p;
}

void printResults(Process p[], int n, float awt, float att, int mct) {
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            p[i].no, p[i].a, p[i].b, p[i].priority, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Completion Time: %d\n", mct);
}

void preemptivePriorityScheduling(Process p[], int n) {
    int time = 0, completed = 0, mct = INT_MIN;
    float awt = 0, att = 0;
    int done[n];
    for (int i = 0; i < n; i++) {
        done[i] = 0;
    }
    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (p[i].a <= time && !done[i] && p[i].priority < highest_priority) {
                highest_priority = p[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            time++;
            p[idx].rt--;
            if (p[idx].rt == 0) {
                done[idx] = 1;
                completed++;
                p[idx].ct = time;
                if (p[idx].ct > mct) {
                    mct = p[idx].ct;
                }
                p[idx].tat = p[idx].ct - p[idx].a;
                p[idx].wt = p[idx].tat - p[idx].b;
                awt += p[idx].wt;
                att += p[idx].tat;
            }
        } else {
            time++;
        }
    }
    awt /= n;
    att /= n;
    printResults(p, n, awt, att, mct);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i] = read(i);
    }
    preemptivePriorityScheduling(p, n);
    
    return 0;
}
