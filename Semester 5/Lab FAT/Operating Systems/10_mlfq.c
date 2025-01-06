#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int no, a, b, rt, wt, tat, ct;
} Process;

Process read(int i) {
    Process p;
    p.no = i + 1;
    printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
    scanf("%d %d", &p.a, &p.b);
    p.rt = p.b;
    return p;
}

void printRemainingTimes(Process* p, int size, const char* level) {
    printf("\n%s Remaining Time Table:\n", level);
    printf("Process\tArrival Time\tBurst Time\tRemaining Time\tCompletion Time\n");
    for (int i = 0; i < size; ++i) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].no, p[i].a, p[i].b,
                p[i].rt, (p[i].rt == 0 ? p[i].ct : -1));
    }
}

void printResults(Process* p, int size, float awt, float att, int mct) {
    printf("\nFinal Results:\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < size; ++i) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].no, p[i].a, p[i].b,
                p[i].ct, p[i].wt, p[i].tat);
    }
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Maximum Completion Time: %d\n", mct);
}

void roundRobinOnePass(Process* p, int size, int tq, int* time) {
    bool inQueue[size];
    for (int i = 0; i < size; ++i) inQueue[i] = false;
    for (int i = 0; i < size; ++i) {
        if (p[i].rt > 0 && !inQueue[i]) {
            inQueue[i] = true;
            if (p[i].rt <= tq) {
                *time += p[i].rt;
                p[i].rt = 0;
                p[i].ct = *time;
            } else {
                *time += tq;
                p[i].rt -= tq;
            }
        }
    }
}

void fcfs(Process* p, int size, int* time) {
    for (int i = 0; i < size; ++i) {
        if (p[i].rt > 0) {
            *time = (*time > p[i].a) ? *time : p[i].a;
            *time += p[i].rt;
            p[i].rt = 0;
            p[i].ct = *time;
        }
    }
}

void mlfq(Process* p, int size, int tq1, int tq2) {
    int time = 0;
    roundRobinOnePass(p, size, tq1, &time);
    printRemainingTimes(p, size, "Level 1");
    roundRobinOnePass(p, size, tq2, &time);
    printRemainingTimes(p, size, "Level 2");
    fcfs(p, size, &time);
    printRemainingTimes(p, size, "Level 3");
    float awt = 0.0f, att = 0.0f;
    int mct = 0;
    for (int i = 0; i < size; ++i) {
        p[i].tat = p[i].ct - p[i].a;
        p[i].wt = p[i].tat - p[i].b;
        awt += p[i].wt;
        att += p[i].tat;
        if (p[i].ct > mct) mct = p[i].ct;
    }
    awt /= size;
    att /= size;
    printResults(p, size, awt, att, mct);
}

int main() {
    int n, tq1, tq2;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum for Level 1: ");
    scanf("%d", &tq1);
    printf("Enter Time Quantum for Level 2: ");
    scanf("%d", &tq2);
    Process* processes = (Process*)malloc(n * sizeof(Process));
    for (int i = 0; i < n; ++i) {
        processes[i] = read(i);
    }
    mlfq(processes, n, tq1, tq2);
    free(processes);
    return 0;
}