/*
Author: pliskinctf
Date: 11th March 2026
Purpose: this project was to practice taking user input with scanf and string concat.
*/

#include <stdio.h>

int main() {
    //using strings instead of char because char can only store one character
    //we will need alot more than one char per variable.
    char persons_name[50];
    char adjective[50];
    char object_name[50];
    char verb[50];
    char silly_word[50];
    int no_of_times;

    printf("enter a person's name: ");
    scanf("%s", persons_name);

    printf("enter an adjective: ");
    scanf("%s", adjective);

    printf("enter an object's name: ");
    scanf("%s", object_name);

    printf("enter a verb: ");
    scanf("%s", verb);

    printf("enter a silly word: ");
    scanf("%s", silly_word);

    printf("enter a random number: ");
    scanf("%d", &no_of_times);

    printf("yesterday, %s found a %s %s that could %s whenever someone said %s\nrandom number:\t %d\n", persons_name, adjective, object_name, verb, silly_word, no_of_times);

    return 0;
}