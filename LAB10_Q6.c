#include <string.h>

#define book 10
#define title 100

int main() {
    char books[book][title];
    char searchTitle[title];
    int found = 0;
    int i;
  
    printf("Enter 10 book titles:\n");
    for ( i = 0; i < title; i++) {
        printf("Book %d: ", i + 1);
        fgets(books[i], title, stdin);
        books[i][strcspn(books[i], "\n")] = '\0';  
    }

   
    printf("\nEnter a book title to search: ");
    fgets(searchTitle,title, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';  


    for ( i = 0; i < books; i++) {
        if (strcmp(books[i], searchTitle) == 0) {
            found = 1;
            break;
        }
    }

 
    if (found)
        printf("\nBook Found\n");
    else
        printf("\nBook Not Found\n");

    return 0;
}

