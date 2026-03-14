#include <stdio.h>

int main()
{
    //declare the variables needed
    double double1;
    double double2;
    double operation_result;
    char operator;

    //take the user input
    printf("what is value 1?: ");
    scanf("%lf", &double1);

    printf("what is value 2?: ");
    scanf("%lf", &double2);

    printf("what is the operation? ('+' for plus, '-' for minus, '*' for product, and '/' for division): \n");
    scanf(" %c", &operator);

    //conditional logic
    switch (operator)
    {
    case '+':
        operation_result = double1 + double2;
        printf("%.4lf %c %.4lf is:\t%.4lf\n", double1, operator, double2, operation_result);
        break;
    case '-':
        operation_result = double1 - double2;
        printf("%.4lf %c %.4lf is:\t%.4lf\n", double1, operator, double2, operation_result);
        break;
    case '*':
        operation_result = double1 * double2;
        printf("%.4lf %c %.4lf is:\t%.4lf\n", double1, operator, double2, operation_result);
        break;
    case '/':
        //to prevent division by 0
        if (double2 == 0) {
            printf("<!--- you tried dividing by 0 ---!>\n");
            break;
        }
        operation_result = double1 / double2;
        printf("%.4lf %c %.4lf is:\t%.4lf\n", double1, operator, double2, operation_result);
        break;
    default:
        printf("invalid input, try again...\n");
        break;
    }

    return 0;
}