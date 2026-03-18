#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    int is_invalid = 0;
    char user_input[50];
    printf("enter a string: ");
    scanf("%49s", user_input);

    size_t length = strlen(user_input);

    for (size_t i = 0; i < length; i++) {

        if (ispunct((unsigned char)user_input[i])) {
            //need to check for shellcode symbols only so we dont block normal ones like '_' etc.
            if (user_input[i] == ';' || user_input[i] == '|' || user_input[i] == '&') {
            is_invalid = 1;
            break;
            }

        }

    }

    if (is_invalid == 0) {
        printf("no invalid input was detected\n");
    } else {
        printf("invalid input was detected\n");
    }

    return 0;
}