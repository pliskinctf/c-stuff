#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	//generated seed
	srand(time(NULL));

	//needed variables
	int computer_choice = (rand() % 100) + 1;
	int strike = 0;
	int player_input;
	int player_won = 0;

	//10 tries
	while (strike <= 10) {

		//display menu and take user input
		printf("tries remaining:\t%d\n", 10 - strike);
		printf("\nGUESS THE NUMBER (its between 0 and 100): ");
		scanf("%d", &player_input);
		
		//validate input
		if (player_input < 1 || player_input > 100) {
			printf("invalid input, try again\n");
			continue;
		}

		//game logic
		if (player_input > computer_choice) {
			printf("wrong answer, try again\n");
			strike++;
			printf("hint: try a smaller number\n");
			continue;
		}
		else if (player_input < computer_choice) {
			printf("wrong answer, try again\n");
			strike++;
			printf("hint: try a bigger number\n");
			continue;
		}

		player_won = 1;

		break;

	}

	if (player_won == 1) {
	printf("\nyou guessed right, YOU WIN\n"); 
	}
	else {
		printf("\nyou lost\n");
	}

	return 0;
}