#include <stdio.h>
#include <string.h>

#define MAX_CITIES 5
#define MAX_LEN 50

int main() {
    char cities[MAX_CITIES][MAX_LEN];
    float temps[MAX_CITIES];

    FILE *fptr;

    for (int i = 0; i < MAX_CITIES; i++) {
        printf("Enter name of city %d: ", i + 1);
        fgets(cities[i], MAX_LEN, stdin);
        cities[i][strcspn(cities[i], "\n")] = '\0'; // remove newline

        printf("Enter average temperature of %s: ", cities[i]);
        scanf("%f", &temps[i]);
        getchar(); 
    }

    fptr = fopen("temperature.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    for (int i = 0; i < MAX_CITIES; i++) {
        fprintf(fptr, "%s %.2f\n", cities[i], temps[i]);
    }

    fclose(fptr);

    char readCity[MAX_LEN];
    float readTemp;

    float highestTemp = -9999;
    char hottestCity[MAX_LEN];

    fptr = fopen("temperature.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    for (int i = 0; i < MAX_CITIES; i++) {
        fscanf(fptr, "%s %f", readCity, &readTemp);

        if (readTemp > highestTemp) {
            highestTemp = readTemp;
            strcpy(hottestCity, readCity);
        }
    }

    fclose(fptr);

    printf("\nCity with the highest temperature: %s (%.2f°C)\n",
           hottestCity, highestTemp);

    return 0;
}

