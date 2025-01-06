# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include<stdbool.h>

typedef struct{
    int id;
    int penalty;
    int deadline;
    int time;
}Job;

void jobSelection(Job jobs[],int n, int level, int currentTime, int currentPenalty, int *minPenalty, bool selected[], bool optimalSelected[]){
    if(n==level){
        if(currentPenalty < *minPenalty){
            *minPenalty = currentPenalty;
            for(int i=0;i<n;i++)
                optimalSelected[i] = selected[i];
        }
        return;
    }
    if(currentTime + jobs[level].time <= jobs[level].deadline){
        selected[level] = true;
        jobSelection(jobs,n,level+1,currentTime+jobs[level].time,currentPenalty,minPenalty,selected,optimalSelected);
        selected[level] = false;
    }
    if(currentPenalty + jobs[level].penalty < *minPenalty)
        jobSelection(jobs,n,level+1,currentTime,currentPenalty+jobs[level].penalty,minPenalty,selected,optimalSelected);
}

int compareIds(const void *a, const void *b){
    Job* JobA =(Job *)a;
    Job* JobB =(Job *)b;
    return JobA->id - JobB->id;
}

int compareJobs(const void *a,const void * b){
    Job* JobA =(Job *)a;
    Job* JobB =(Job *)b;
    return JobA->deadline - JobB->deadline;
}

void scheduleJobs(Job jobs[],int n){
    int minPenalty = INT_MAX;
    bool selected[n];
    bool optimalSelected[n];
    for(int i=0;i<n;i++){
        selected[i] = false;
        optimalSelected[i] = false;
    }
    jobSelection(jobs,n,0,0,0,&minPenalty,selected,optimalSelected);
    int max_id =0;
    int cost = 0;
    int upperbound = 0;
    for(int i=0;i<n;i++){
        if(optimalSelected[i]){
            if(max_id <jobs[i].id){
                max_id = i;
            }
        }
        else{
            upperbound += jobs[i].penalty;
        }
    }
    for(int i=0;i<n;i++){
        if(!optimalSelected[i] && max_id > jobs[i].id){
            cost += jobs[i].penalty;
        }
    }
    printf("Cost %d\n",cost);
    printf("Upper Bound %d\n",upperbound);
    Job completed[n];
    int count = 0;
    for(int i=0;i<n;i++){
        if(optimalSelected[i]){
            completed[count++] = jobs[i];
        }
    }
    qsort(completed,count,sizeof(Job),compareIds);
    for(int i=0;i<count;i++){
        printf("J%d ",completed[i].id);
    }
}

int main(){
    Job jobs[]={
        {1, 5, 1, 1},
        {2, 10, 3, 2},
        {3, 6, 2, 1},
        {4, 3, 1, 1}
    };
    int n = sizeof(jobs)/sizeof(jobs[0]);
    qsort(jobs,n,sizeof(Job),compareJobs);
    scheduleJobs(jobs,n);
    return 0;
}