#include <stdio.h>

struct process {
    char pname[10];
    int bt, rt, wt, tt;
} p[10], t;

int main() {
    int t[15];
    int temp, tq, n, i;
    int count, sq, times = 0;
    float sum = 0.0, suml = 0.0;
    printf("Enter the value for quantum time: ");
    scanf("%d", &tq);
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", p[i].pname);
        printf("Enter the burst time for process %s: ", p[i].pname);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }
    printf("Gantt chart:\n");
    sq = 0;
    while (1) {
        count = 0;
        for (i = 0; i < n; i++) {
            temp = tq;
            if (p[i].rt == 0) {
                count++;
                continue;
            }
            if (p[i].rt >= tq) {
                p[i].rt -= tq;
            } else if (p[i].rt > 0) {
                temp = p[i].rt;
                p[i].rt = 0;
            }
            t[times++] = sq;
            sq += temp;
            p[i].tt = sq;
            printf("\t%s", p[i].pname);
            t[times] = sq;
        }
        if (count == n) {
            break;
        }
    }
    for (i = 0; i < n; i++) {
        p[i].wt = p[i].tt - p[i].bt;
        sum += p[i].wt;
        suml += p[i].tt;
    }
    printf("\n");
    for (i = 0; i <= times; i++) {
        printf("\t%d", t[i]);
    }
    printf("\nThe average waiting time = %f\n", sum / n);
    printf("The average turnaround time = %f\n", suml / n);
    return 0;
}
