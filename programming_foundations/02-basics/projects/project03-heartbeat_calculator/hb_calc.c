#include <stdio.h>

int main() {
    int current_year;
    int birth_year;

    printf("what year is it currently?: ");
    scanf("%d", &current_year);

    printf("what year were you born in?: ");
    scanf("%d", &birth_year);

    int current_age = current_year - birth_year;
    long long int total_heartbeats_so_far = (long long int)current_age * 365 * 24 * 60 * 80;

    printf("you are approx: %d years old!\nyour heart has approx beat %lld times so far!\n", current_age, total_heartbeats_so_far);

    return 0;
}