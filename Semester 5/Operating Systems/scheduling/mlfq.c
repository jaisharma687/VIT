#include <stdio.h>

struct process {
    char name;
    int AT, BT, WT, TAT, RT, CT;
} Q1[10], Q2[10], Q3[10];

int n;

void sortByArrival() {
    struct process temp;
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(Q1[i].AT > Q1[j].AT) {
                temp = Q1[i];
                Q1[i] = Q1[j];
                Q1[j] = temp;
            }
        }
    }
}

int main() {
    int i, j, k = 0, r = 0, time = 0;
    int tq1, tq2, flag = 0;
    char c;
    float totalWT = 0, totalTAT = 0, avgWT = 0, avgTAT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum for first queue (tq1): ");
    scanf("%d", &tq1);
    printf("Enter time quantum for second queue (tq2): ");
    scanf("%d", &tq2);
    for(i = 0, c = 'A'; i < n; i++, c++) {
        Q1[i].name = c;
        printf("Enter the arrival time and burst time of process %c: ", Q1[i].name);
        scanf("%d %d", &Q1[i].AT, &Q1[i].BT);
        Q1[i].RT = Q1[i].BT;
    }
    sortByArrival();
    time = Q1[0].AT;
    printf("\nProcess in first queue following RR with qt = %d", tq1);
    printf("\nProcess\t\tAT\t\tBT\t\tWT\t\tTAT\t\tCT");
    for(i = 0; i < n; i++) {
        if(Q1[i].AT > time)
            time = Q1[i].AT;
        if(Q1[i].RT <= tq1) {
            time += Q1[i].RT;
            Q1[i].RT = 0;
            Q1[i].CT = time;
            Q1[i].TAT = Q1[i].CT - Q1[i].AT;
            Q1[i].WT = Q1[i].TAT - Q1[i].BT;
            totalWT += Q1[i].WT;
            totalTAT += Q1[i].TAT;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", Q1[i].name, Q1[i].AT, Q1[i].BT, Q1[i].WT, Q1[i].TAT, Q1[i].CT);
        } 
        else {
            Q2[k].AT = Q1[i].AT;
            Q2[k].BT = Q1[i].BT;
            time += tq1;
            Q1[i].RT -= tq1;
            Q2[k].RT = Q1[i].RT;
            Q2[k].name = Q1[i].name;
            k++;
            flag = 1;
        }
    }
    if(flag == 1) {
        printf("\n\nProcess in second queue following RR with qt = %d", tq2);
        printf("\nProcess\t\tAT\t\tBT\t\tWT\t\tTAT\t\tCT");
    }
    for(i = 0; i < k; i++) {
        if(Q2[i].RT <= tq2) {
            time += Q2[i].RT;
            Q2[i].RT = 0;
            Q2[i].CT = time;
            Q2[i].TAT = Q2[i].CT - Q2[i].AT;
            Q2[i].WT = Q2[i].TAT - Q2[i].BT;
            totalWT += Q2[i].WT;
            totalTAT += Q2[i].TAT;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", Q2[i].name, Q2[i].AT, Q2[i].BT, Q2[i].WT, Q2[i].TAT, Q2[i].CT);
        } 
        else {
            Q3[r].AT = Q2[i].AT;
            Q3[r].BT = Q2[i].BT;
            time += tq2;
            Q2[i].RT -= tq2;
            Q3[r].RT = Q2[i].RT;
            Q3[r].name = Q2[i].name;
            r++;
            flag = 2;
        }
    }
    if(flag == 2) {
        printf("\n\nProcess in third queue following FCFS");
        printf("\nProcess\t\tAT\t\tBT\t\tWT\t\tTAT\t\tCT");
    }
    for(i = 0; i < r; i++) {
        if(i == 0 || Q3[i].AT > time)
            time = Q3[i].AT;
        Q3[i].CT = time + Q3[i].BT;
        time = Q3[i].CT;
        Q3[i].TAT = Q3[i].CT - Q3[i].AT;
        Q3[i].WT = Q3[i].TAT - Q3[i].BT;
        totalWT += Q3[i].WT;
        totalTAT += Q3[i].TAT;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", Q3[i].name, Q3[i].AT, Q3[i].BT, Q3[i].WT, Q3[i].TAT, Q3[i].CT);
    }
    avgWT = totalWT / n;
    avgTAT = totalTAT / n;
    printf("\n\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);
    return 0;
}