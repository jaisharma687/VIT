# include <stdio.h>
int main() {
    const int maxInput = 100;//we cannot again assign the value of maxInput by making it constant using const keyword
    int i;
    double number, average, sum = 0.0;
    for (i = 1; i <= maxInput; i++) {
        printf("%d. Enter a number: ", i);
        scanf("%lf", &number);
        // go to jump if the user enters a negative number
        if (number < 0.0) {
            goto jump;
        }
        sum += number;
    }
    // printf("%d",i);
    jump:{//goto is a keyword and jump is just a variable that we have defined
        average = sum / (i - 1);
    }
    printf("Sum = %.2f\n", sum);//%.2f format specifier for precision of 2
    printf("Average = %.2f", average);
    return 0;
}