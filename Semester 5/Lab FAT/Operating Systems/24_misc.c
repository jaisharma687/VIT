#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void perform_operation(char op, int num1, int num2) {
    int result;
    switch (op) {
        case '+':
            result = num1 + num2;
            printf("I am child %d. I am performing addition operation.\n", getpid());
            printf("Sum: %d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("I am child %d. I am performing subtraction operation.\n", getpid());
            printf("Difference: %d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("I am child %d. I am performing multiplication operation.\n", getpid());
            printf("Product: %d * %d = %d\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("I am child %d. I am performing division operation.\n", getpid());
                printf("Quotient: %d / %d = %d\n", num1, num2, result);
            } else {
                printf("I am child %d. I am performing division operation.\n", getpid());
                printf("Error: Division by zero.\n");
            }
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }
    printf("Child %d exiting.\n", getpid());
    exit(0);
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    pid_t pids[4];
    char operations[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < 4; i++) {
        pids[i] = fork();

        if (pids[i] == 0) {
            perform_operation(operations[i], num1, num2);
        } else if (pids[i] < 0) {
            perror("Fork failed");
            exit(1);
        }
    }

    for (int i = 0; i < 4; i++) {
        int status;
        pid_t pid = waitpid(pids[i], &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process with PID %d exited with status %d.\n", pid, WEXITSTATUS(status));
        }
    }

    return 0;
}
