#include <stdio.h>

int main()
{
	int cpu_number_hardcoded = 61;
	int player_guess;

	printf("guess the number (hint: its between 0 and 100): ");
	scanf("%d", &player_guess);
	
	if (player_guess > 100 || player_guess < 0)
	{
		printf("you have to pick a number between 1 and 100\n");
	}
	else if (player_guess == cpu_number_hardcoded)
	{
		printf("its a draw!\n");
	}
	else if (player_guess > cpu_number_hardcoded)
	{
		printf("you win!\n");
	}
	else
	{
		printf("you lose!\n");
	}
	
	return 0;
}
