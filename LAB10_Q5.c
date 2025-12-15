#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    char specialChars[] = "!@#$%^&*()-_=+[]{}|;:',.<>/?`~";

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

  
    password[strcspn(password, "\n")] = '\0';

    int length = strlen(password);
    int hasSpecial = 0;

    for (int i = 0; specialChars[i] != '\0'; i++) {
        if (strchr(password, specialChars[i]) != NULL) {
            hasSpecial = 1;
            break;
        }
    }

   
    if (length < 6) {
        printf("Password Strength: Weak\n");
    }
    else if (length >= 6 && length < 10) {
        if (hasSpecial)
            printf("Password Strength: Medium\n");
        else
            printf("Password Strength: Weak\n");
    }
    else {  
        if (hasSpecial)
            printf("Password Strength: Strong\n");
        else
            printf("Password Strength: Medium\n");
    }

    return 0;
}
