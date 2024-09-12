#include <stdio.h>

int main() {
    int n, j, temp, templ, temp2,i;
    int pr[10], b[10], t[10], w[10], p[10], ar[10], s[10], g[10];
    float att = 0, awt = 0;
    for (i = 0; i < 10; i++) {
        b[i] = 0;
        w[i] = 0;
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) p[i] = i;
    for (i = 0; i < n; i++) {
        printf("Enter the burst time of p[%d]: ", p[i]);
        scanf("%d", &b[i]);
        printf("Enter the priority value of p[%d]: ", p[i]);
        scanf("%d", &ar[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ar[i] > ar[j] || (ar[i] == ar[j] && b[i] > b[j])) {
                
                temp2 = ar[i];
                ar[i] = ar[j];
                ar[j] = temp2;
                
                templ = p[i];
                p[i] = p[j];
                p[j] = templ;
                
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    printf("\nProcess Name\tBurst Time\tPriority\n");
    for (i = 0; i < n; i++)
        printf("p[%d]\t\t%d\t\t%d\n", p[i], b[i], ar[i]);
    w[0] = 0;
    for (i = 1; i < n; i++) {
        w[i] = w[i - 1] + b[i - 1];
    }
    for (i = 0; i < n; i++) {
        s[i] = w[i] + b[i];
        t[i] = s[i];
        awt += w[i];
        att += t[i];
    }
    awt /= n;
    att /= n;
    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("p[%d]\t\t%d\t\t%d\n", p[i], w[i], t[i]);
    }
    printf("\nGANTT CHART:\n");
    printf("0");
    for (i = 0; i < n; i++) {
        printf("\tp[%d]\t", p[i]);
        printf("%d", s[i]);
    }
    printf("\nThe average waiting time is: %.2f\n", awt);
    printf("The average turnaround time is: %.2f\n", att);
    return 0;
}