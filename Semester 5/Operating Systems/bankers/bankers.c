#include <stdio.h>

int main() {
    int n, m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m];
    int max[n][m];
    int avail[m];

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Allocation of Process P%d, Resource R%d: ", i, j);
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Maximum demand of Process P%d, Resource R%d: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int j = 0; j < m; j++) {
        printf("Available Resource R%d: ", j);
        scanf("%d", &avail[j]);
    }

    printf("\nProcesses:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", i);
    }
    printf("\n\nResources:\n");
    for (int j = 0; j < m; j++) {
        printf("Resource R%d ", j);
    }
    printf("\n\nAvailable Resources:\n");
    for (int j = 0; j < m; j++) {
        printf("R%d: %d ", j, avail[j]);
    }
    printf("\n\n");

    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++) {
        f[k] = 0;
    }

    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The system is not in a safe state\n");
            break;
        }
    }

    if (flag == 1) {
        printf("Following is the SAFE Sequence:\n");
        for (int i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}
