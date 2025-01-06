#include <stdio.h>
#include <limits.h>

struct Process {
    int a, b, no, wt, tat, rt, ct;
};

struct Process read(int i) {
    struct Process p;
    printf("The process no.: %d\n", i + 1);
    p.no = i + 1;
    printf("Enter the arrival time: ");
    scanf("%d", &p.a);
    printf("Enter the burst time: ");
    scanf("%d", &p.b);
    p.rt = p.b;
    return p;
}

void printResults(struct Process p[], float awt, float att, int n, int mct) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].no, p[i].a, p[i].b, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Completion Time: %d\n", mct);
}

void srtf(struct Process p[], int n) {
    float awt = 0, att = 0;
    int curr_time = 0, completed = 0, mct = INT_MIN;
    int done[100] = {0};
    while (completed < n) {
        int idx = -1, min_burst = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].a <= curr_time && p[i].rt < min_burst) {
                min_burst = p[i].rt;
                idx = i;
            }
        }
        if (idx == -1) {
            curr_time++;
            continue;
        }
        p[idx].rt--;
        curr_time++;
        if (p[idx].rt == 0) {
            done[idx] = 1;
            completed++;
            p[idx].ct = curr_time;
            if (p[idx].ct > mct) mct = p[idx].ct;
            p[idx].tat = p[idx].ct - p[idx].a;
            p[idx].wt = p[idx].tat - p[idx].b;
            awt += p[idx].wt;
            att += p[idx].tat;
        }
    }
    awt /= n;
    att /= n;
    printResults(p, awt, att, n, mct);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process p[100];
    for (int i = 0; i < n; i++) {
        p[i] = read(i);
    }
    
    srtf(p, n);
    return 0;
}