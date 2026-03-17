#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {

    srand(time(NULL));

    int player_health = 30;
    //int max_health = 50;
    int potions_in_inventory = 1;
    int gold_in_inventory = 0;

    for (int room_no = 1; room_no <= 5; room_no++) {

        printf("\nnow entering room %d\n", room_no);

        int roll = (rand() % 10) + 1;

        if (roll <=3) {
            while (1)
            {
                printf("a monster has appeared!\n");

                int monster_health = (rand() % 11) + 5;
                int player_attack_dmg;
                int monster_attack_dmg;
                int battle_menu_input;

                do
                {
                    printf("\nmonster health:\t%d\n", monster_health);
                    printf("players health:\t%d\n", player_health);
                    printf("potions:       \t%d\n", potions_in_inventory);

                    printf("\n1-Attack\n2-Drink Potion (+10HP)\n3-Quit\nchoose an option: ");
                    scanf("%d", &battle_menu_input);

                    if (battle_menu_input != 1 && battle_menu_input != 2 && battle_menu_input != 3) {
                        printf("invalid input, try again.\n");
                        continue;
                    }

                    if (battle_menu_input == 1) {
                        printf("player is now attacking...\n");
                        player_attack_dmg = (rand() % 6) + 3;
                        monster_health -= player_attack_dmg;

                        sleep(1);

                        printf("monster is now attacking...\n");
                        monster_attack_dmg = (rand() % 6) + 2;
                        player_health -= monster_attack_dmg;
                    } else if (battle_menu_input == 2) {
                        if (potions_in_inventory > 0) {
                            player_health += 10;
                            potions_in_inventory--;
                            continue;
                        } else {
                            printf("you do not have any potions\n");
                            continue;
                        }
                    } else {
                        printf("goodbye\n");
                        return 1; 
                    }

                    if (player_health > 0 && monster_health <= 0) {
                        int monster_gold_drop = (rand() % 11) + 5;
                        gold_in_inventory += monster_gold_drop;

                        if (rand() % 4 == 0) {
                            printf("the monster dropped %d gold and 1 potion\n", monster_gold_drop);
                            printf("you now have %d gold and %d potion(s)\n", gold_in_inventory, potions_in_inventory);
                        } else {
                            printf("the monster dropped %d gold\n", monster_gold_drop);
                            printf("you now have %d gold and %d potion(s)\n", gold_in_inventory, potions_in_inventory);
                        }
                        break;
                    }

                } while (player_health > 0 && monster_health > 0);

                break;
                
            }
            
        }
        else if (roll <=6) {
            while (1)
            {
                printf("you found a treasure chest!\n");
                int gold_found = (rand() % 20) + 10;
                gold_in_inventory += gold_found;

                if (rand() % 4 == 0) {
                    printf("the chest contained %d gold and 1 potion\n", gold_found);
                    printf("you know have %d gold and %d potion(s)\n", gold_in_inventory, potions_in_inventory);
                    break;
                } else {
                    printf("you found %d gold!\n", gold_found);
                    printf("you know have %d gold and %d potion(s)\n", gold_in_inventory, potions_in_inventory);
                    break;
                }
            }
        }
        else if (roll <=8) {
            while (1)
            {
            printf("you fell into a trap!, you took 15 damage\n");
            player_health -= 15;
            if (player_health <= 0) {
                break;
            } else {
                printf("your remaining health is:\t%d\n", player_health);
                break;
            }
            }
            
        }
        else {
            while (1)
            {
            printf("there is nothing on this room\n");
            break;
            }
        }

        if (player_health <= 0) {
            printf("you died in room %d... game over\n", room_no);
            break;
        }

        while(1) {
            int user_input_for_rest;
            printf("do you want to rest? (1-Yes (+5HP) 2-No): ");
            scanf("%d", &user_input_for_rest);
            if (user_input_for_rest != 1 && user_input_for_rest != 2) {
                printf("invalid input, try again");
                continue;
            }

            if (user_input_for_rest == 1) {
                player_health += 5;
                printf("your health is now:\t%d\n", player_health);
            } else {
                printf("continuing to next room\n");
            }

            break;
        }

    }

    if (player_health > 0) {
        printf("VICTORY... you cleared all 5 rooms!\n");
    }

    return 0;
}