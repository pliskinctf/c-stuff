#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CREDENTIAL_COUNTER 10 //can store a total of 10 credentials
#define STRING_LENGTH 200     //max length for a string is 200 bytes

int main()
{
    char usernames[CREDENTIAL_COUNTER][STRING_LENGTH];
    char passwords[CREDENTIAL_COUNTER][STRING_LENGTH];

    int counter = 0; //to keep track of state

    while (1)
    {
        //display menu
        printf("\n=================================\n");
        printf("1- Add New Password\n");
        printf("2- Quit Program\n");
        printf("=================================\n");

        int user_input_for_menu; //take user input and validate
        do
        {
            //i do want to do the /r thing here, but lets just get something working right now
            printf("choose an option: ");
            scanf("%d", &user_input_for_menu); //later change this to fgets() as well
            getchar();

            if (user_input_for_menu != 1 && user_input_for_menu != 2) {
                printf("invalid input, try again\n");
            } else if (user_input_for_menu == 1) {
                user_input_for_menu = 1;
                break;
            } else {
                user_input_for_menu = 2; //later add the quit logic right here
                break;
            }

        } while (user_input_for_menu != 1 && user_input_for_menu != 2);

        //2- Quit's logic
        if (user_input_for_menu == 2) {
            printf("goodbye...\n");
            break;
        }

        //1- Add New Password's logic
        if (user_input_for_menu == 1) {

            char username_to_store[200]; //this will be used in strcpy

            while (1) //for the username
            {
                //take the username
                char username_buffer[200];

                printf("enter username: ");
                fgets(username_buffer, sizeof(username_buffer), stdin);
                username_buffer[strcspn(username_buffer, "\n")] = '\0';

                //validate username_buffer (strip whitespace, shellcode etc.)
                size_t username_buffer_length = strlen(username_buffer);

                int starting_index = 0;
                int ending_index = strlen(username_buffer) - 1;

                
                for (size_t user_i = 0; user_i < username_buffer_length; user_i++) {

                    //shellcode validation
                    if (ispunct(username_buffer[user_i]) != 0) {
                        //only check for shellcode symbols so you dont block normal ones
                        if (username_buffer[user_i] == ';' || username_buffer[user_i] == '|' || username_buffer[user_i] == '&') {
                            printf("invalid input, try again");
                            break; //will break the for loop, and go back to while(1) for the username
                        }
                    }

                    //remove whitespaces
                    while (isspace(username_buffer[starting_index]) != 0) {
                        starting_index++;
                    }

                    while (ending_index > starting_index && isspace(username_buffer[ending_index])) {
                        ending_index--;
                    }

                    username_buffer[ending_index + 1] = '\0'; //should this be moved outside for for loop?

                }

                //take the validated username and store it in username_to_store
                snprintf(username_to_store, sizeof(username_to_store), "%s", &username_buffer[starting_index]);

                printf("username:\t%s\n", username_to_store); //remove this line, only for testing

                break; //we will use the 'username_to_store' array later on
            }

            char password_to_store[100];
            while (1) //for the password
            {
                char password_buffer[100];
                printf("enter your password: ");
                fgets(password_buffer, sizeof(password_buffer), stdin);
                password_buffer[strcspn(password_buffer, "\n")] = '\0';

                //validate password input and strip whitespace
                size_t length = strlen(password_buffer);

                int starting_index = 0;
                int ending_index = length - 1;

                for (size_t pass_i = 0; pass_i < length; pass_i++) {
                    while (isspace(password_buffer[starting_index]) != 0) {
                        starting_index++;
                    }

                    while (ending_index > starting_index && isspace(password_buffer[starting_index]) != 0) {
                        ending_index--;
                    }

                    password_buffer[ending_index + 1] = '\0';
                    
                }

                //take the validated password and store it in password_to_store
                snprintf(password_to_store, sizeof(password_to_store), "%s", &password_buffer[starting_index]);

                printf("password:\t%s\n", password_to_store); //remove this line after testing is done as well.

                break;
            }

            //now we have to strcpy the validated credentials and store it in the array, also update counter

            
        }
        
        break; //break out of while(1)
    }
    

    return 0;
}