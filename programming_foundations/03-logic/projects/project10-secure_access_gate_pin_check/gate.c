#include <stdio.h>

int main() {
    //declared the variables needed
    int pin_code;
    int access_code;

    //taking user input for the PIN code, and then validating it.
    printf("enter your 4 digit PIN code: ");
    scanf("%d", &pin_code);

    if (pin_code < 1000 || pin_code > 9999) {
        printf("PIN code must be 4 digits only, please try again.\n");
        return 0;
    }
    else if (pin_code != 1234 && pin_code != 1111) {
        printf("invalid PIN code, please try again.\n");
        return 0;
    }

    //once the PIN code is validated, now we validate the user's access level
    printf("enter your access level (1 or 2): ");
    scanf("%d", &access_code);

    if (access_code != 1 && access_code != 2) {
        printf("invalid access_code, must be either 1 or 2\n");
        return 0;
    }
    else if (pin_code == 1234 && access_code == 2)
    {
        printf("welcome admin user\n");
    }
    else if (pin_code == 1111 && access_code == 1)
    {
        printf("welcome user.\n");
    }
    else {
        printf("invalid credentials, please try again.\n");
    }

    return 0;
}