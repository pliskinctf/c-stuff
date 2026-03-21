#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CAPACITY 5
#define INPUT_MAX_CAPACITY 200

int main() {
    //store and track inventory
    int inventory[MAX_CAPACITY] = {0};
    int count = 0;

    while (1) {

        char menu_buffer[INPUT_MAX_CAPACITY];
        char add_buffer[INPUT_MAX_CAPACITY];
        char delete_buffer[INPUT_MAX_CAPACITY];
        int menu_input = 0;

        do //print menu and take/validate user input for menu
        {
            printf("\n=================\n");
            printf("1- Add Item\n");
            printf("2- List All Items\n");
            printf("3- Delete a Item\n");
            printf("4- Quit\n");
            printf("==================\n");
            printf("choose an option: ");

            fgets(menu_buffer, sizeof(menu_buffer), stdin);
            menu_buffer[strcspn(menu_buffer, "\n")] = '\0';

            menu_input = atoi(menu_buffer);

            if (menu_input != 1 && menu_input != 2 && menu_input !=3 && menu_input !=4) {
                printf("invalid input, try again.\n");
                continue;
            }
            
        } while (menu_input != 1 && menu_input != 2 && menu_input !=3 && menu_input !=4);

        //now logic for the rest of the program
        switch (menu_input)
        {
        case 1:
            //do something
            break;
        case 2:
            //do something
            break;
        case 3:
            //do something
            break;
        case 4:
            //do something
            break;
        default:
            printf("something went wrong during the switch statement\n");
            break;
        }
        
        break; //break out of while(1)
    }

    return 0;
    
}