#include <stdio.h>

int main() {
    FILE *file;
    char name[50];
    int count = 0;

    file = fopen("attendance.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open attendance.txt\n");
        return 1;
    }

    printf("= Attendance List =\n");

    while (fscanf(file, "%s", name) != EOF) {
        printf("%s\n", name);
        count++;
    }

    fclose(file);

    printf("\nTotal students present: %d\n", count);

    return 0;
}

