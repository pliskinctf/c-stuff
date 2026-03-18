#include <stdio.h>

int main() 
{
    char screen_buffer[1024];
    
    char player_name[] = "pliskinctf";
    char rank[] = "Diamond 1";
    char kd_ratio[] = "3.1";
    char game_currency[] = "800 coins";

    snprintf(screen_buffer, sizeof(screen_buffer), 
    "\n======================\n"
    "username:\t%s\n"
    "rank:\t%s\n"
    "K/D ratio:\t%s\n"
    "currency:\t%s\n"
    "======================\n",
    player_name, rank, kd_ratio, game_currency);

    printf("%s\n", screen_buffer);

    return 0;
}