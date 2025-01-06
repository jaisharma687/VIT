#include <stdio.h>

typedef struct item_details {
    char itemName[30];
    int quantity;
    float price;
    float totalAmount;
} item;

int main()
{
    item thing[50];
    int i, choice;
    int count = 0;
    float expenses = 0.0f;\
    i = 0;
    do {
        printf("Enter item details %d:\n", i + 1);
        printf("Item: ");
        fgets(thing[i].itemName, 30, stdin);
        printf("Price: ");
        scanf("%f", &thing[i].price);
        printf("Quantity: ");
        scanf("%d", &thing[i].quantity);
        thing[i].totalAmount = (float)thing[i].quantity * thing[i].price;
        expenses += thing[i].totalAmount;
        i++;
        count++;
        printf("Want to more items (press 1): ");
        scanf("%d", &choice);
        getchar();
    } while (choice == 1);

    printf("All details are:\n");
    for (i = 0; i < count; i++) {
        printf("%s%.2f\t%d\t%.2f\n", thing[i].itemName, thing[i].price, thing[i].quantity, thing[i].totalAmount);
    }
    printf("Total expense: %.2f\n", expenses);

    printf("Want to divide in friends (press 1 for yes): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Number of friends: ");
        scanf("%d", &i);
        printf("Each friend will have to pay: %.2f\n", (expenses / (float)i));
    }return 0;
}
