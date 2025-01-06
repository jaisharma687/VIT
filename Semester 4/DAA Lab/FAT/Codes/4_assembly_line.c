#include <stdio.h>

#define MAX_STATIONS 100

int entry[] = {4,2};
int x[] = {3,7};

int s1[] = {2,8,9,3,4,1};
int s2[] = {6,11,2,2,7,3};

int t1[] = {3,1,2,1,3};
int t2[] = {3,4,1,1,3};


int min(int a, int b) {
    return (a < b) ? a : b;
}

int assemblyTime(int n) {
    int f1[MAX_STATIONS], f2[MAX_STATIONS];
    
    f1[0] = entry[0] + s1[0];
    f2[0] = entry[1] + s2[0];

    for (int j = 1; j < n; j++) {
        f1[j] = min(f1[j - 1] + s1[j], f2[j - 1] + t2[j - 1] + s1[j]);
        f2[j] = min(f2[j - 1] + s2[j], f1[j - 1] + t1[j - 1] + s2[j]);
    }

    return min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
}

void printOptimalPath(int n) {
    int f1[MAX_STATIONS], f2[MAX_STATIONS];
    int path[MAX_STATIONS];

    f1[0] = entry[0] + s1[0];
    f2[0] = entry[1] + s2[0];

    for (int j = 1; j < n; j++) {
        if (f1[j - 1] + s1[j] <= f2[j - 1] + t2[j - 1] + s1[j]) {
            f1[j] = f1[j - 1] + s1[j];
            path[j] = 1; 
        } else {
            f1[j] = f2[j - 1] + t2[j - 1] + s1[j];
            path[j] = 2;  
        }

        if (f2[j - 1] + s2[j] <= f1[j - 1] + t1[j - 1] + s2[j]) {
            f2[j] = f2[j - 1] + s2[j];
            path[j] = 2;
        } else {
            f2[j] = f1[j - 1] + t1[j - 1] + s2[j];
            path[j] = 1;
        }
    }
    int finalLine = (f1[n - 1] + x[0] < f2[n - 1] + x[1]) ? 1 : 2;

    printf("Optimal Path: \n");
    for (int j = 0; j < n; j++) {
        printf("Station %d, Line %d\n", j+1, path[j]);
    }
    printf("Exit Line %d\n", finalLine);
}


int main() {
    int n=6;
    int totalTime = assemblyTime(n);
    printOptimalPath(n);
    printf("%d\n", totalTime);
    return 0;
}