#include <stdio.h>
#include <stdbool.h>

#define P 3 

void printWaitForGraph(bool waitForGraph[P][P]) {
    printf("Wait-For Graph:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d -> ", i);
        for (int j = 0; j < P; j++) {
            if (waitForGraph[i][j]) {
                printf("P%d ", j);
            }
        }
        printf("\n");
    }
}

bool detectCycleUtil(bool waitForGraph[P][P], int v, bool visited[], bool recStack[]) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
        for (int i = 0; i < P; i++) {
            if (waitForGraph[v][i]) {
                if (!visited[i] && detectCycleUtil(waitForGraph, i, visited, recStack)) {
                    return true;
                } else if (recStack[i]) {
                    return true;
                }
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool detectCircularWait(bool waitForGraph[P][P]) {
    bool visited[P] = {0};
    bool recStack[P] = {0};
    for (int i = 0; i < P; i++) {
        if (detectCycleUtil(waitForGraph, i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

void recoverDeadlock(bool waitForGraph[P][P]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            if (waitForGraph[i][j]) {
                printf("Recovery action: Release resources from process P%d\n", j);
                waitForGraph[i][j] = false;
                return;
            }
        }
    }
}

int main() {
    bool waitForGraph[P][P] = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    printWaitForGraph(waitForGraph);
    if (detectCircularWait(waitForGraph)) {
        printf("Circular wait detected!\n");
        recoverDeadlock(waitForGraph);
        printf("Deadlock recovery attempted.\n");
        printWaitForGraph(waitForGraph);
    } else {
        printf("No circular wait detected.\n");
    }
    return 0;
}