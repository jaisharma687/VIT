#include <stdio.h>

int main() {
    int n, j, temp, temp1, temp2;
    int pr[10], b[10], t[10], w[10], p[10], i, ar[10], s[10], g[10];
    float att = 0, awt = 0;
    for (i = 0; i < 10; i++) {
        b[i] = 0;
        w[i] = 0;
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the burst time of p[%d]: ", i + 1);
        scanf("%d", &b[i]);
        printf("Enter the arrival time of p[%d]: ", i + 1);
        scanf("%d", &ar[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ar[i] > ar[j] || (ar[i] == ar[j] && b[i] > b[j])) {
                temp2 = ar[i];
                ar[i] = ar[j];
                ar[j] = temp2;

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;

                temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;
            }
        }
    }
    printf("\nProcess name\tBurst time\tArrival time\n");
    for (i = 0; i < n; i++) {
        printf("p[%d]\t\t%d\t\t%d\n", p[i], b[i], ar[i]);
    }
    w[0] = 0;
    for (i = 1; i < n; i++) {
        w[i] = w[i - 1] + b[i - 1];
        s[i - 1] = s[i - 1] + b[i - 1];
    }
    s[n - 1] = w[n - 1] + b[n - 1];
    for (i = 0; i < n; i++) {
        t[i] = s[i] - ar[i];
        awt += w[i];
        att += t[i];
    }
    awt /= n;
    att /= n;
    printf("\nProcess\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("p[%d]\t\t%d\t\t%d\n", p[i], w[i], t[i]);
    }
    printf("\nGANTT CHART:\n");
    printf("0");
    for (i = 0; i < n; i++) {
        printf(" -- p[%d] -- %d", p[i], s[i]);
    }
    printf("\n\nThe average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);
    return 0;
}