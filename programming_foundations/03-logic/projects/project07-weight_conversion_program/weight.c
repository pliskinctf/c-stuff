#include <stdio.h>

//Pre Processor
#define KG_TO_LBS 2.20462

int main() {
    double weight_in_kgs;

    printf("what is the weight in kilograms?: ");
    scanf("%lf", &weight_in_kgs);

    double weight_in_lbs = weight_in_kgs * KG_TO_LBS;

    printf("your weight in pounds (lbs) is:\t%.2lf\n", weight_in_lbs);

    return 0;
}