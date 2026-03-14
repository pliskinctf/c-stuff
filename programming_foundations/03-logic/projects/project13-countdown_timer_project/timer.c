#include <stdio.h>
#include <unistd.h>

int main() 
{
    int player_input;

    printf("enter the number of seconds for the timer: ");
    scanf("%d", &player_input);

    for (int i = player_input; i >=0; i--) {
        printf("Time Left:\t%d\n", i);
        sleep(1);
    }

    printf("\n!ALARM SOUND!\n");

    return 0;
}