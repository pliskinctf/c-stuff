#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char password_buffer[100];
    
    printf("enter your password for analysis: ");
    fgets(password_buffer, sizeof(password_buffer), stdin);

    password_buffer[strcspn(password_buffer, "\n")] = '\0';

    int has_uppercase = 0;
    int has_specialchar = 0; //ispunct
    int has_digit = 0;
    int has_lower = 0;
    int good_password_length = 0;

    int length = strlen(password_buffer);

    for (int i = 0; i < length; i++) {
        if (isupper(password_buffer[i]) != 0) {
            has_uppercase = 1;
        } else if (ispunct(password_buffer[i]) != 0) {
            has_specialchar = 1;
        } else if (isdigit(password_buffer[i]) != 0) {
            has_digit = 1;
        } else if (islower(password_buffer[i]) != 0) {
            has_lower = 1;
        }

    }

    if (length > 8) {
        good_password_length = 1;
    }

    int password_score = has_uppercase + has_specialchar + has_digit + has_lower + good_password_length;
    if (password_score <=2) {
        printf("weak password... fix it\n");
    }
    else if (password_score <=4) {
        printf("moderate password... could be improved\n");
    }
    else {
        printf("strong password... good job\n");
    }

    return 0;
}