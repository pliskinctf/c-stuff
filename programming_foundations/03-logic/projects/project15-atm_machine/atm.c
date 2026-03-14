#include <stdio.h>
#include <unistd.h>

int main()
{
    //needed variables
    double bank_balance= 90000.00;
    char currency= '$';
    int pin_code= 1234;
    int remaining_login_attempts= 5;
    int login_user_input;
    int user_authenticated = 0;
    int menu_user_input;

    //authentication
    do
    {
        printf("enter your login code: ");
        scanf("%d", &login_user_input);

        if (login_user_input !=pin_code && remaining_login_attempts > 0) {
            remaining_login_attempts--;
            printf("invalid login code, try again... redirecting\n");
            sleep(1);
        }
        else if (remaining_login_attempts <= 0) {
            printf("entered wrong password too many times, try again later\n");
            return 1;
        }
        else {
            user_authenticated = 1;
            break;
        }

    } while (user_authenticated == 0);


    while (1)
    {
    //if the user successfully logs in, then do this
        printf("\nchoose an option: \n1- Print Balance\n2- Deposit Amount\n3- Withdraw Amount\n4- Exit\n");
        scanf("%d", &menu_user_input);

        switch (menu_user_input)
        {
        case 1:
            printf("Your Current Balance is:\t%c%.2lf\n", currency, bank_balance);
            break;

        case 2:
            double user_input_for_deposit;
            printf("how much would you like to deposit?: ");
            scanf("%lf", &user_input_for_deposit);
            bank_balance = bank_balance + user_input_for_deposit;
            printf("Your New Balance is:\t%c%.2lf\n", currency, bank_balance);
            break;

        case 3:
            //if balance > 0... then allow this to run
            if (bank_balance <= 0) {
                printf("your account is empty, you can not access this option...");
                return 0;
            }
            else {
                double user_input_for_withdraw_amount;
                printf("Your Current Balance is:\t%c%.2lf\n", currency, bank_balance);
                printf("how much do you want to withdraw?: ");
                scanf("%lf", &user_input_for_withdraw_amount);
                //if the withdraw amount is greater than the bank balance, block the transaction
                if (user_input_for_withdraw_amount > bank_balance) {
                    printf("you have insufficient funds, transaction failed");
                    return 0;
                }

                printf("you withdrew\t%c%.2lf\n", currency, user_input_for_withdraw_amount);
                bank_balance -= user_input_for_withdraw_amount;
                printf("Your Current Balance is:\t%c%.2lf\n", currency, bank_balance);

            }

            break;

        case 4:
            printf("goodbye\n");
            return 0;
            break;

        default:
            printf("invalid input\n");
            break;
        }
        }
   
    return 0;
}