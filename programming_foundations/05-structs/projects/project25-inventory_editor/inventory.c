#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CAPACITY 5
#define INPUT_MAX_CAPACITY 200

int main() {
    //store and track inventory
    char inventory[MAX_CAPACITY][INPUT_MAX_CAPACITY];
    int count = 0;

    while (1) {

        char menu_buffer[INPUT_MAX_CAPACITY];
        char add_buffer[INPUT_MAX_CAPACITY];
        char delete_buffer[INPUT_MAX_CAPACITY];
        int repeat_loop = 0;
        int menu_input = 0;
        int exit_program = 0; //bool

        do //print menu and take/validate user input for menu
        {
            printf("\n=================\n");
            printf("1- Add Item\n");
            printf("2- List All Items\n");
            printf("3- Delete An Item\n");
            printf("4- Quit\n");
            printf("==================\n");
            printf("choose an option: ");

            fgets(menu_buffer, sizeof(menu_buffer), stdin);
            menu_buffer[strcspn(menu_buffer, "\n")] = '\0';

            printf("\n"); //just to make the UI cleaner

            menu_input = atoi(menu_buffer);

            if (menu_input != 1 && menu_input != 2 && menu_input !=3 && menu_input !=4) {
                printf("invalid input, try again.\n");
                continue;
            }
            
        } while (menu_input != 1 && menu_input != 2 && menu_input !=3 && menu_input !=4);

        //now logic for the CRUD operations... no 'U' cuz not needed in inventory stuff ig
        switch (menu_input)
        {

        //ADD ITEM TO INVENTORY
        case 1:
            //bounds check
            if (count < MAX_CAPACITY) 
            { 

                char item_to_add[INPUT_MAX_CAPACITY]; //to hold the validated input for the item

                while(1) {
                    //take user input for adding a task
                    printf("what would you like to add to your inventory: ");
                    fgets(add_buffer, sizeof(add_buffer), stdin);
                    add_buffer[strcspn(add_buffer, "\n")] = '\0';

                    //check for shellcode
                    size_t length = strlen(add_buffer);
                    for (size_t i = 0; i < length; i++) {
                        if (ispunct(add_buffer[i]) != 0) {

                            if (add_buffer[i] == ';' || add_buffer[i] == '|' || add_buffer[i] == '&') {
                                printf("invalid input, no shellcode allowed\n");
                                break; //will go back to while(1) to take input again
                            }

                        }
                    }

                    //trim whitespaces now
                    int starting_index = 0;
                    while (isspace(add_buffer[starting_index]))
                    {
                        starting_index++;
                    }

                    int ending_index = length - 1; //minus 1 to not include any potential '\0'
                    while (ending_index > starting_index && isspace(add_buffer[ending_index]))
                    {
                        ending_index--;
                    }

                    add_buffer[ending_index + 1] = '\0';

                    //now add the item to the inventory array
                    snprintf(item_to_add, sizeof(item_to_add), "%s", &add_buffer[starting_index]);

                    strcpy(inventory[count], item_to_add);
                    printf("\n!LOG!: you added %s at index %d in your inventory\n", inventory[count], count);
                    count++;

                    break; //exit the while(1)
                }

            }
            else 
            {
                printf("inventory is full, can not add more items\n");
            }

            break;

        //LIST ALL ITEMS IN INVENTORY
        case 2:
        if (count != 0) 
        {
            for (int i = 0; i < count; i++) {
                printf("item no: %d:\t%s\n", i + 1, inventory[i]);
            }
            break;
        }
        else 
        {
            printf("inventory is empty, no items to list\n");
            break;
        }

        //DELETE AN ITEM FROM THE INVENTORY
        case 3:
            if (count != 0) 
            {
                printf("delete logic...\n"); //remove AFTER testing
                //print menu for delete

                //take user input with fgets (delete_buffer)

                //delete logic

                break;
            } 
            else 
            {
                printf("there is nothing in your inventory to delete...\n");
                break;
            }

        //EXIT PROGRAM
        case 4:
            exit_program = 1;
            printf("goodbye...\n");
            break;

        default:
            printf("something went wrong during the switch statement\n");
            break;
        }
        
        if (exit_program == 1) {
            break;
        }

        do
        {
            printf("\nexit inventory? (1 for yes, 0 for no): ");
            scanf("%d", &repeat_loop);
            getchar();

        } while (repeat_loop != 1 && repeat_loop != 0);

        if (repeat_loop == 1) 
        {
            break; //exit while(1)
        }
        else 
        {
            continue; //repeat while(1)
        }

    }

    return 0;
    
}