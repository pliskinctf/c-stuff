#include <stdio.h>

int main() {
    int player_energy_level = 10;
    int player_input;

    while (player_energy_level > 0) {

        //display menu
        printf("\nCurrent Energy Level:\t%d\n", player_energy_level);
        printf("OPTIONS:\n1 - Explore (-2 energy)\n2 - Rest    (+1 energy)\n0 - Quit Game\n");

        //take user input
        printf("choose an option (1, 2, or 0): ");
        scanf("%d", &player_input);

        //logic to handle the user input
        if (player_input != 1 && player_input != 2 && player_input != 0) {
            printf("invalid input, please try again\n");
            continue;
        }
        else if (player_input == 1) {
            printf("exploring...\n");
            player_energy_level = player_energy_level - 2;
            continue;
        }
        else if (player_input == 2) {
            printf("resting...\n");
            player_energy_level++;
            continue;
        }
        else {
            break; //this wille exit the while loop
        }

    }

    if (player_energy_level <= 0) {
        printf("\nyou ran out of energy :(\nthe traveller is resting, come back another time.\n");
    }
    else {
        printf("\ngoodbye\n");
    }

    return 0;
}