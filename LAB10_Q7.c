#include <stdio.h>

int main() {
    FILE *file;
    char category[50];
    double amount;

    file = fopen("expenses.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter expense category: ");
    scanf("%49s", category);

    printf("Enter expense amount: ");
    scanf("%lf", &amount);

    fprintf(file, "%s %.2lf\n", category, amount);
    fclose(file);

    printf("\nExpense added successfully!\n");

    file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("\n=== ALL EXPENSES ===\n");

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    
    return 0;
}

