#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int id;
    int penalty;
    int deadline;
    int time;
} Job;

int compareJobs(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->deadline - jobB->deadline;
}

int compareIds(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->id - jobB->id;
}

void branchAndBound(Job jobs[], int n, int level, int currentTime, int currentPenalty, int* minPenalty, bool selected[], bool optimalSelected[]) {
    if (level == n) {
        if (currentPenalty < *minPenalty) {
            *minPenalty = currentPenalty;
            for (int i = 0; i < n; i++) {
                optimalSelected[i] = selected[i];
            }
        }
        return;
    }
    if (currentTime + jobs[level].time <= jobs[level].deadline) {
        selected[level] = true;
        branchAndBound(jobs, n, level + 1, currentTime + jobs[level].time, currentPenalty, minPenalty, selected, optimalSelected);
        selected[level] = false;
    }
    if (currentPenalty + jobs[level].penalty < *minPenalty) {
        branchAndBound(jobs, n, level + 1, currentTime, currentPenalty + jobs[level].penalty, minPenalty, selected, optimalSelected);
    }
}

void scheduleJobs(Job jobs[], int n) {
    
    int minPenalty = INT_MAX;
    bool selected[n];
    bool optimalSelected[n];
    for (int i = 0; i < n; i++) {
        selected[i] = false;
        optimalSelected[i] = false;
    }
    branchAndBound(jobs, n, 0, 0, 0, &minPenalty, selected, optimalSelected);
    int max_id = 0;
    int cost = 0;
    int upperBound = 0;
    for (int i = 0; i < n; i++) {
        if (!optimalSelected[i]) {
            upperBound += jobs[i].penalty;
        }else{
            if(max_id < jobs[i].id){
                max_id=i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if(optimalSelected[i] == false && max_id > jobs[i].id){
            cost += jobs[i].penalty;
        }
    }
    printf("Cost = %d\n", cost);
    printf("Upper Bound = %d\n", upperBound);
    printf("Jobs Completed within deadline are ");
    Job completedJobs[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (optimalSelected[i]) {
            completedJobs[count++] = jobs[i];
        }
    }
    qsort(completedJobs, count, sizeof(Job), compareIds);
    for (int i = 0; i < count; i++) {
        if(i==0){
            printf("J%d and ", completedJobs[i].id);
        }
        else{
            printf("J%d", completedJobs[i].id);
        }
    }
    printf("\n");
}


int main() {
    Job jobs[] = {
        {1, 5, 1, 1},
        {2, 10, 3, 2},
        {3, 6, 2, 1},
        {4, 3, 1, 1}
    };
    int n = sizeof(jobs)/sizeof(jobs[0]);
    
    qsort(jobs, n, sizeof(Job), compareJobs);
    scheduleJobs(jobs, n);
    return 0;
}
