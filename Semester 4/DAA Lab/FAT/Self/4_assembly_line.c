#include <stdio.h>

# define MAX 20

int min(int a, int b){
    return (a<b)?a:b;
}

void printPath(int path[], int n, int finalLine) {
    printf("Optimal Solution\n");
    for(int i=0;i<n;i++){
        printf("Station %d Line %d\n",i+1,path[i]);
    }
    printf("Exit Line %d\n",finalLine);
}

void assemblyLine(int e[],int x[],int s1[],int s2[],int t1[],int t2[],int n){
    int f1[MAX], f2[MAX], path1[MAX], path2[MAX];
    f1[0] = e[0] + s1[0];
    f2[0] = e[1] + s2[0];
    path1[0] = 1;
    path2[0] = 2;
    for(int i=1;i<n;i++){
        if(f1[i-1] + s1[i] <= f2[i-1] + t2[i-1] + s1[i]){
            f1[i] = f1[i-1] + s1[i];
            path1[i] = 1;
        }
        else{
            f1[i] = f2[i-1] + t2[i-1] + s1[i];
            path1[i] = 2;
        }
        if(f2[i-1] + s2[i] <= f1[i-1] + t1[i-1] + s2[i]){
            f2[i] = f2[i-1] + s2[i];
            path2[i] = 2;
        }
        else{
            f2[i] = f1[i-1] + t1[i-1] + s2[i];
            path2[i] = 1;
        }
    }

    int finalLine;
    if(f1[n-1] + x[0] < f2[n-1] + x[1]){
        finalLine = 1;
        printPath(path1, n, finalLine);
        printf("%d\n",f1[n-1] + x[0]);
    }
    else{
        finalLine = 2;
        printPath(path2, n, finalLine);
        printf("%d\n",f2[n-1] + x[1]);
    }
}

int main(){
    int e[] = {4,2};
    int x[] = {3,7};
    int s1[] = {2,8,9,3,4,1};
    int s2[] = {6,11,2,2,7,3};
    int t1[] = {3,1,2,1,3};
    int t2[] = {3,4,1,1,3};
    assemblyLine(e,x,s1,s2,t1,t2,6);
    return 0;
}