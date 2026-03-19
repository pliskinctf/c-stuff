#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    //will store the user's first and last name from user input
    char user_input[100];
    //will store the email
    char email[200];

    //take the user's input with fgets
    printf("enter your name: ");
    fgets(user_input, sizeof(user_input), stdin);

    //now we have to remove any potential whitespaces
    int starting_index = 0;
    while (isspace(user_input[starting_index])) {
        starting_index++;
    }

    int ending_index = strlen(user_input) - 1;
    while (ending_index > starting_index && isspace(user_input[ending_index])) {
        ending_index--;
    }

    //now we have the starting and ending points of the actual text, we add a \0
    user_input[ending_index + 1] = '\0';

    //now we can start formatting the string for the email
    for (int i = starting_index; user_input[i] != '\0'; i++) {
        user_input[i] = tolower(user_input[i]);

        if (isspace(user_input[i])) {
            user_input[i] = '.'; //replace any white spaces between the text with '.'
        }
    }

    //print the output
    snprintf(email, sizeof(email), "%s@gmail.com", &user_input[starting_index]);
    printf("your email is:\t%s\n", email);
    
    return 0;
}