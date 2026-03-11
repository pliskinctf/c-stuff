#include <stdio.h>
#include <math.h>

int main() {
    double fahrenheit_value;

    printf("enter the temprature (in fahrenheit): ");
    scanf("%lf", &fahrenheit_value);

    double celsius_value = ((fahrenheit_value - 32) * 5.0) / 9.0;

    printf("the temprature in celsius is:\t%.2lf\n", celsius_value);

    return 0;
}