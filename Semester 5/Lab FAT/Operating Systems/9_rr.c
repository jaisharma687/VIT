#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int no, b, a, rt, wt, tat, ct;
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
    return p;
}

void printResults(Process* p, int n, float awt, float att, int mct) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                p[i].no, p[i].a, p[i].b,
                p[i].ct, p[i].wt, p[i].tat);
    }
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Completion Time: %d\n", mct);
}

void roundRobin(Process* p, int n, int tq) {
    int time = 0, completed = 0, mct = INT_MIN;
    float awt = 0, att = 0;
    int readyQueue[n];
    int front = 0, rear = -1;
    bool inQueue[n];
    for (int i = 0; i < n; i++) {
        inQueue[i] = false;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].a > p[j + 1].a) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n && p[i].a <= time; i++) {
        readyQueue[++rear] = i;
        inQueue[i] = true;
    }
    while (completed < n) {
        if (front > rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (p[i].a <= time && p[i].rt > 0 && !inQueue[i]) {
                    readyQueue[++rear] = i;
                    inQueue[i] = true;
                }
            }
            continue;
        }
        int index = readyQueue[front++];
        if (p[index].rt > 0) {
            if (p[index].rt <= tq) {
                time += p[index].rt;
                p[index].rt = 0;
                p[index].ct = time;
                mct = (mct > p[index].ct) ? mct : p[index].ct;
                p[index].tat = time - p[index].a;
                p[index].wt = p[index].tat - p[index].b;
                awt += p[index].wt;
                att += p[index].tat;
                completed++;
            } else {
                time += tq;
                p[index].rt -= tq;
            }
        }
        for (int i = 0; i < n; i++) {
            if (p[i].a <= time && p[i].rt > 0 && !inQueue[i]) {
                readyQueue[++rear] = i;
                inQueue[i] = true;
            }
        }
        if (p[index].rt > 0) {
            readyQueue[++rear] = index;
            inQueue[index] = true;
        }
    }
    awt /= n;
    att /= n;
    printResults(p, n, awt, att, mct);
}

int main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process* p = malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        p[i] = read(i);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    roundRobin(p, n, tq);
    free(p);
    return 0;
}