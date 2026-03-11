#include <stdio.h>

int main() {
    int user_age;
    printf("enter your age to see if you are eligible to vote: ");
    scanf("%d", &user_age);

    printf("the answer is (1 for yes, 0 for no):\t%d\n", user_age >= 18);

    return 0;
}