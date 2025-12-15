#include <stdio.h>
#include <string.h>

#define guest 5
#define name 50

int main() {
    char guests[guest][name];
    int rooms[guest];

    FILE *fptr;

    
    printf("Enter hotel booking records:\n");
    for (int i = 0; i < guest; i++) {
        printf("\nEnter guest name %d: ", i + 1);
        fgets(guests[i], name, stdin);
        guests[i][strcspn(guests[i], "\n")] = '\0'; 

        printf("Enter room number for %s: ", guests[i]);
        scanf("%d", &rooms[i]);
        getchar(); 
    }

    fptr = fopen("hotel.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < guest; i++) {
        fprintf(fptr, "%s %d\n", guests[i], rooms[i]);
    }
    fclose(fptr);

    printf("\nRecords saved to hotel.txt successfully.\n");

    char searchName[name];
    char readName[name];
    int readRoom;
    int found = 0;

    printf("\nEnter guest name to search: ");
    fgets(searchName, name, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    fptr = fopen("hotel.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    while (fscanf(fptr, "%s %d", readName, &readRoom) == 2) {
        if (strcmp(searchName, readName) == 0) {
            printf("\nGuest found!\n");
            printf("Name: %s\nRoom Number: %d\n", readName, readRoom);
            found = 1;
            break;
        }
    }

    fclose(fptr);

    if (!found) {
        printf("\nGuest not found in hotel records.\n");
    }

    return 0;
}

